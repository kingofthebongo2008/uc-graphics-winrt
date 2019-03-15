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

        public MainPage()
        {
            this.InitializeComponent();

            m_ctx       = new ResourceCreateContext();
            m_swapChain = new CompositionSwapChainResources(m_ctx, m_swapChainPanel);

            var display = DisplayInformation.GetForCurrentView();
            display.DpiChanged += new TypedEventHandler<DisplayInformation, object>(OnDpiChanged);
        }


        private void OnDpiChanged( DisplayInformation d, object o)
        {
            m_swapChain.WaitForGpu();
            m_swapChain.SetDisplayInformation(d);
        }

        private void M_swapChainPanel_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            m_swapChain.WaitForGpu();

            UniqueCreator.Graphics.Size2D s;

            s.m_width   = (float)e.NewSize.Width;
            s.m_height  = (float)e.NewSize.Height;

            m_swapChain.SetLogicalSize(s);

            /*
            std::unique_lock < std::mutex > lock (m_render_lock) ;
            //stall and do not submit more work
            m_device_resources->WaitForGpu();
            m_background_swap_chain->WaitForGpu();

            //Reset view dependent heaps
            m_depth_buffer.reset();
            m_device_resources->ResetViewDependentResources();

            //Recreate the resources and buffers
            UniqueCreator::Graphics::Size2D size = { args->NewSize.Width, args->NewSize.Height };

            m_background_swap_chain->SetLogicalSize(size);
            m_depth_buffer = m_resource_create_context->CreateViewDepthBuffer(m_background_swap_chain->GetBackBuffer()->GetSize2D(), UniqueCreator::Graphics::DepthBufferFormat::Depth32Float);
            */
        }

        private void M_swapChainPanel_CompositionScaleChanged(SwapChainPanel sender, object args)
        {
            m_swapChain.WaitForGpu();
            m_swapChain.SetCompositionScale(sender.CompositionScaleX, sender.CompositionScaleY);
        }
    }
}
