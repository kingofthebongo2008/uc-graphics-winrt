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
        private object m_rendererLock         = new object();
        private IAsyncAction                  m_renderLoopWorker;

        public MainPage()
        {
            this.InitializeComponent();

            m_ctx = new ResourceCreateContext();
            m_swapChain = new CompositionSwapChainResources(m_ctx, m_swapChainPanel);

            var display = DisplayInformation.GetForCurrentView();
            display.DpiChanged += new TypedEventHandler<DisplayInformation, object>(OnDpiChanged);

            /*unit test

            var description = new BlendDescription();
            RenderTargetBlendDescription d;
            d.BlendEnable = true;
            d.BlendOperation = BlendOperation.Add;
            d.BlendOperationAlpha = BlendOperation.Add;
            d.DestinationBlend = Blend.DestinationAlpha;
            d.DestinationBlendAlpha = Blend.DestinationAlpha;
            d.LogicOperation = LogicOperation.And;
            d.LogicOperationEnable = false;
            d.RenderTargetWriteMask = 0;
            d.SourceBlend = Blend.DestinationAlpha;
            d.SourceBlendAlpha = Blend.DestinationAlpha;

            description.AlphaToCoverageEnable = true;
            description.RenderTargets.Add(d);

            var d0 = new RenderTargetBlendDescription[1];
            d0[0] = d;

            description.RenderTargets = d0;

            var code = new VertexShaderByteCode();

            var bytes = new byte[120];

            for ( var i = 0;  i < 120; ++i)
            {
                bytes[i] = (byte)i;
            }

            code.Code = bytes;
            */

            var code = UniqueCreator.Graphics.Gpu.Shaders.compute_cs.Factory.Create();
            var description = new ComputePipelineStateDescription();
            description.CS = code;
            var pipeline = new ComputePipelineState(m_ctx, description);

            var triangleVertex = UniqueCreator.Graphics.Gpu.Shaders.triangle_vertex.Factory.Create();
            var trianglePixel  = UniqueCreator.Graphics.Gpu.Shaders.triangle_pixel.Factory.Create();

            var description2    = new GraphicsPipelineStateDescription();

            var rasterizerState = new RasterizerDescription();

            var samples = new SampleDescription
            {
                Count = 1,
                Quality = 0
            };

            var depthStencil = new DepthStencilDescription
            {
                DepthEnable = false,
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


            rasterizerState.CullMode = CullMode.None;
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

            description2.VS                             = triangleVertex;
            description2.PS                             = trianglePixel;
            description2.SampleMask                     = 0xFFFFFFFF;
            description2.RasterizerState                = rasterizerState;
            description2.PrimitiveTopology              = PrimitiveTopologyType.Triangle;
            description2.Samples                        = samples;
            description2.DepthStencilState              = depthStencil;
            description2.DsvFormat = GraphicsFormat.D32_Single;
            description2.IbStripCutValue = IndexBufferStripCut.ValueDisabled;
            description2.BlendState = blendState;
            description2.RtvFormats.Add(GraphicsFormat.R8G8B8A8_UNORM);

            m_triangle = new GraphicsPipelineState(m_ctx, description2);



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
                var ctx = m_swapChain.CreateGraphicsComputeCommandContext();
                var backBuffer = m_swapChain.BackBuffer;

                ctx.SetGraphicsPipelineStateObject(m_triangle);
                ctx.SetDescriptorHeaps();

                ctx.TransitionResource(backBuffer, ResourceState.Present, ResourceState.RenderTarget);
                ctx.SetRenderTarget(m_swapChain.BackBuffer);
                ctx.Clear(m_swapChain.BackBuffer);

                ctx.SetPrimitiveTopology(PrimitiveTopology.TriangleList);

                {
                    Size2D s = m_swapChain.BackBuffer.Size2D;

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



                ctx.Draw(3, 0);

                ctx.TransitionResource(backBuffer, ResourceState.RenderTarget, ResourceState.Present);

                ctx.Submit();
            }
           
            m_swapChain.Present();

            m_swapChain.MoveToNextFrame();

            m_ctx.Sync();
            m_swapChain.Sync();
        }
    }
}
