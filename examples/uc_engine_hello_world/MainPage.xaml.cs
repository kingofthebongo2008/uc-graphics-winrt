using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Graphics.Display;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.System.Threading;

using UniqueCreator.Graphics.Gpu;

namespace uc_engine_hello_world
{

    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private ResourceCreateContext         m_ctx;
        private CompositionSwapChainResources m_swapChain;
        private GraphicsPipelineState         m_triangle;
        private ComputePipelineState          m_compute;
        private object m_rendererLock         = new object();
        private IAsyncAction                  m_renderLoopWorker;
        private ByteAddressBuffer             m_buffer;
        private Texture2D                     m_texture;


        GraphicsPipelineState makeTriangle(ResourceCreateContext ctx)
        {
            var triangleVertex = UniqueCreator.Graphics.Gpu.Shaders.triangle_vertex.Factory.Create();
            var trianglePixel = UniqueCreator.Graphics.Gpu.Shaders.triangle_pixel.Factory.Create();

            var description2 = new GraphicsPipelineStateDescription();

            var rasterizerState = new RasterizerDescription();

            var samples = new SampleDescription
            {
                Count = 1,
                Quality = 0
            };

            var depthStencil = new DepthStencilDescription
            {
                DepthEnable = true,
                StencilEnable = false,
                DepthWriteMask = DepthWriteMask.All,
                DepthFunc = ComparisonFunction.Less
            };

            depthStencil.BackFace.StencilFailOperation = StencilOperation.Keep;
            depthStencil.BackFace.StencilPassOperation = StencilOperation.Keep;
            depthStencil.BackFace.StencilFunction = ComparisonFunction.Always;
            depthStencil.BackFace.StencilDepthFailOperation = StencilOperation.Keep;
            depthStencil.FrontFace = depthStencil.BackFace;
            depthStencil.StencilReadMask = 0xff;
            depthStencil.StencilWriteMask = 0xff;


            rasterizerState.CullMode = CullMode.Back;
            rasterizerState.FillMode = FillMode.Solid;
            rasterizerState.FrontCounterClockwise = true;
            rasterizerState.AntialiasedLineEnable = false;
            rasterizerState.ConservativeRaster = ConservativeRasterizationMode.Off;
            rasterizerState.DepthBias = 0;
            rasterizerState.DepthBiasClamp = 0.0f;
            rasterizerState.SlopeScaledDepthBias = 0.0f;
            rasterizerState.DepthClipEnable = true;
            rasterizerState.ForcedSampleCount = 0;
            rasterizerState.MultisampleEnable = false;

            var blendState = new BlendDescription
            {
                AlphaToCoverageEnable = false,
                IndependentBlendEnable = false
            };

            var blend = new RenderTargetBlendDescription
            {
                BlendEnable = false,
                LogicOperationEnable = false,
                BlendOperation = BlendOperation.Add,
                BlendOperationAlpha = BlendOperation.Add,
                LogicOperation = LogicOperation.Clear,
                DestinationBlend = Blend.DestinationColor,
                DestinationBlendAlpha = Blend.DestinationAlpha,
                SourceBlend = Blend.SourceColor,
                SourceBlendAlpha = Blend.SourceAlpha,
                RenderTargetWriteMask = 0xF
            };

            blendState.RenderTargets = new RenderTargetBlendDescription[] { blend };

            description2.VS = triangleVertex;
            description2.PS = trianglePixel;
            description2.SampleMask = 0xFFFFFFFF;
            description2.RasterizerState = rasterizerState;
            description2.PrimitiveTopology = PrimitiveTopologyType.Triangle;
            description2.Samples = samples;
            description2.DepthStencilState = depthStencil;
            description2.DsvFormat = GraphicsFormat.D32_Single;
            description2.IbStripCutValue = IndexBufferStripCut.ValueDisabled;
            description2.BlendState = blendState;
            description2.RtvFormats.Add(GraphicsFormat.R8G8B8A8_UNORM);

            return new GraphicsPipelineState(ctx, description2);
        }

        ComputePipelineState makeCompute(ResourceCreateContext ctx)
        {
            var code = UniqueCreator.Graphics.Gpu.Shaders.compute_cs.Factory.Create();
            var description = new ComputePipelineStateDescription();
            description.CS = code;
            return new ComputePipelineState(m_ctx, description);
        }

        // Generate a simple black and white checkerboard texture.
        byte[] GenerateTextureData()
        {
            const uint TextureWidth = 256;
            const uint TextureHeight = 256;
            const uint TexturePixelSize = 1;    // The number of bytes used to represent a pixel in the texture.

            const uint rowPitch     = TextureWidth * TexturePixelSize;
            const uint cellPitch    = rowPitch >> 3;        // The width of a cell in the checkboard texture.
            const uint cellHeight   = TextureWidth >> 3;    // The height of a cell in the checkerboard texture.
            const uint textureSize  = rowPitch * TextureHeight;

            byte[] data = new byte[textureSize];

            for (uint n = 0; n < textureSize; n += TexturePixelSize)
            {
                var x = n % rowPitch;
                var y = n / rowPitch;
                var i = x / cellPitch;
                var j = y / cellHeight;

                if (i % 2 == j % 2)
                {
                    data[n] = 0x00;        // R
                }
                else
                {
                    data[n] = 0xff;        // R
                }
            }

            return data;
        }


        public MainPage()
        {
            this.InitializeComponent();

            m_ctx = new ResourceCreateContext();
            m_swapChain = new CompositionSwapChainResources(m_ctx, m_swapChainPanel);

            var display = DisplayInformation.GetForCurrentView();
            display.DpiChanged += new TypedEventHandler<DisplayInformation, object>(OnDpiChanged);
            m_triangle = makeTriangle(m_ctx);
            m_compute = makeCompute(m_ctx);

            m_buffer = m_ctx.CreateByteAddressBuffer(4096, ResourceState.CopyDestination);

            m_texture = m_ctx.CreateTexture2D( 256, 256, 1, GraphicsFormat.R8_UNORM, ResourceState.CopyDestination );

            var ctx = m_swapChain.CreateGraphicsComputeCommandContext();

            {
                float[] positions =
                {
                    0.0f, 0.5f, 0.5f, 1.0f,
                    -0.5f, 0.0f, 0.5f, 1.0f,
                    0.5f, 0.0f, 0.5f, 1.0f
                };

                byte[] b0 = new byte[positions.Length * 4];
                Buffer.BlockCopy(positions, 0, b0, 0, b0.Length);

                float[] colors =
                {
                    1.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 1.0f
                };

                byte[] b1 = new byte[colors.Length * 4];
                Buffer.BlockCopy(colors, 0, b1, 0, b1.Length);

                ctx.UpdateBuffer(m_buffer, 0, b0);
                ctx.UpdateBuffer(m_buffer, (uint)b0.Length, b1);
            }

            {
                var subResourceData = new SubresourceData();

                subResourceData.Data         = GenerateTextureData();
                subResourceData.RowPitch     = 256;
                subResourceData.SlicePitch   = 256 * 256;

                SubresourceData[] datas      = { subResourceData };

                ctx.UploadResource(m_texture, 0, 1, datas);
            }

            ctx.TransitionResource(m_texture, ResourceState.CopyDestination, ResourceState.PixelShaderResource | ResourceState.NonPixelShaderResource);
            ctx.TransitionResource(m_buffer, ResourceState.CopyDestination, ResourceState.NonPixelShaderResource );

            ctx.SubmitAndWaitToExecute();
        }

        public void OnResuming()
        {
            // If the animation render loop is already running then do not start another thread.
            if (m_renderLoopWorker != null && m_renderLoopWorker.Status == AsyncStatus.Started)
            {
                return;
            }

            // Create a task that will be run on a background thread.
            var workItemHandler = new WorkItemHandler((action) =>
            {
                // Calculate the updated frame and render once per vertical blanking interval.
                while (action.Status == AsyncStatus.Started)
                {
                    lock (m_rendererLock)
                    {
                        Render();
                    }
                }
            });

            // Run task on a dedicated high priority background thread.
            m_renderLoopWorker = ThreadPool.RunAsync(workItemHandler, WorkItemPriority.High, WorkItemOptions.TimeSliced);

        }

        public void OnSuspending()
        {
            // If the animation render loop is already running then do not start another thread.
            if (m_renderLoopWorker != null && m_renderLoopWorker.Status == AsyncStatus.Started)
            {
                m_renderLoopWorker.Cancel();
                m_renderLoopWorker = null;
            }
        }

        private void OnDpiChanged( DisplayInformation d, object o)
        {
            lock (m_rendererLock)
            {
                m_swapChain.WaitForGpu();
                m_ctx.ResetViewDependentResources();
                m_swapChain.SetDisplayInformation(d);
            }
        }

        private void M_swapChainPanel_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            lock (m_rendererLock)
            {
                m_swapChain.WaitForGpu();
                m_ctx.ResetViewDependentResources();

                UniqueCreator.Graphics.Gpu.Size2D s;
                s.Width = (float)e.NewSize.Width;
                s.Height = (float)e.NewSize.Height;
                m_swapChain.SetLogicalSize(s);
            }
        }

        private void M_swapChainPanel_CompositionScaleChanged(SwapChainPanel sender, object args)
        {
            lock (m_rendererLock)
            {
                m_swapChain.WaitForGpu();
                m_ctx.ResetViewDependentResources();
                m_swapChain.SetCompositionScale(sender.CompositionScaleX, sender.CompositionScaleY);
            }
        }
        private void Render()
        {
            {
                var ctx                 = m_swapChain.CreateGraphicsComputeCommandContext();
                var backBuffer          = m_swapChain.BackBuffer;
                var size                = backBuffer.Size2D;
                var w                   = (uint)backBuffer.Size2D.Width;
                var h                   = (uint)backBuffer.Size2D.Height;

                var frameColorBuffer    = m_ctx.CreateFrameColorBuffer(w, h, GraphicsFormat.R8G8B8A8_UNORM, ResourceState.RenderTarget);
                var frameDepthBuffer    = m_ctx.CreateFrameDepthBuffer(w, h, DepthBufferFormat.Depth32Single, ResourceState.DepthWrite);
                var postProcess         = m_ctx.CreateFrameColorBuffer(w, h, GraphicsFormat.R8G8B8A8_UNORM, ResourceState.UnorderedAccess);

                ctx.SetRenderTarget(frameColorBuffer, frameDepthBuffer);
                ctx.SetGraphicsPipelineStateObject(m_triangle);
                ctx.SetDescriptorHeaps();
                ctx.Clear(frameColorBuffer);
                ctx.Clear(frameDepthBuffer);

                ctx.SetPrimitiveTopology(PrimitiveTopology.TriangleList);

                {
                    Size2D s = size;

                    {
                        ViewPort v;

                        v.MinDepth = 0.0f;
                        v.MaxDepth = 1.0f;
                        v.TopLeftX = 0.0f;
                        v.TopLeftY = 0.0f;
                        v.Width = s.Width;
                        v.Height = s.Height;
                        ctx.SetViewPort(v);
                    }

                    {
                        Rectangle2D v;

                        v.Left = 0;
                        v.Top = 0;
                        v.Right = s.Width;
                        v.Bottom = s.Height;

                        ctx.SetScissorRectangle(v);
                    }
                }

                ctx.SetGraphicsSRV(5, 0, m_buffer);
                ctx.SetGraphicsSRV(5, 1, m_texture);
                ctx.Draw(3, 0);

                ctx.TransitionResource(frameColorBuffer, ResourceState.RenderTarget, ResourceState.NonPixelShaderResource);
                ctx.SetComputePipelineStateObject(m_compute);

                ctx.SetComputeUAV(4, 0, postProcess);
                ctx.SetComputeSRV(5, 0, frameColorBuffer);
                ctx.Dispatch((w + 7) / 8, (h + 7) / 8, 1);

                ctx.TransitionResource(backBuffer, ResourceState.Present, ResourceState.CopyDestination);
                ctx.TransitionResource(postProcess, ResourceState.UnorderedAccess, ResourceState.CopySource);
                ctx.CopyResource(backBuffer, postProcess);
                ctx.TransitionResource(backBuffer, ResourceState.CopyDestination, ResourceState.Present);
                ctx.Submit();
            }
           
            m_swapChain.Present();

            m_swapChain.MoveToNextFrame();

            m_ctx.Sync();
            m_swapChain.Sync();
        }
    }
}
