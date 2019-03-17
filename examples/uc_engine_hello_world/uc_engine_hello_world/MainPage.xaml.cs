using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.System.Threading;

using Windows.Graphics.Display;

using UniqueCreator.Graphics;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace uc_engine_hello_world
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private ResourceCreateContext         m_ctx;
        private CompositionSwapChainResources m_swapChain;
        private object m_rendererLock         = new object();
        private IAsyncAction                  m_renderLoopWorker;

        public MainPage()
        {
            this.InitializeComponent();

            m_ctx       = new ResourceCreateContext();
            m_swapChain = new CompositionSwapChainResources(m_ctx, m_swapChainPanel);

            var display = DisplayInformation.GetForCurrentView();
            display.DpiChanged += new TypedEventHandler<DisplayInformation, object>(OnDpiChanged);
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

                UniqueCreator.Graphics.Size2D s;
                s.m_width = (float)e.NewSize.Width;
                s.m_height = (float)e.NewSize.Height;
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
                var ctx = m_swapChain.CreateDirectCommandContext();
                var backBuffer = m_swapChain.BackBuffer;

                ctx.Copy();
                ctx.Dispatch();
                ctx.Draw();
                ctx.TransitionResource(backBuffer, ResourceState.Present, ResourceState.RenderTarget);

                ctx.Clear(m_swapChain.BackBuffer);

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
