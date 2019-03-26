#include "pch.h"
#include "CompositionSwapChainResources.h"
#include "BackBuffer.h"
#include "IFenceHandleNative.h"

#include <uc/gx/dx12/dx12.h>
#include "WindowsEnvironment.h"


namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
        using BackBuffer1 = BackBuffer;

        std::unique_ptr<uc::gx::dx12::gpu_command_queue> create_command_queue(ID3D12Device* d, D3D12_COMMAND_LIST_TYPE type)
        {
            Microsoft::WRL::ComPtr<ID3D12CommandQueue>                      present_queue;
            {
                auto desc = D3D12_COMMAND_QUEUE_DESC();
                desc.Type = type;
                present_queue = uc::gx::dx12::create_command_queue(d, &desc);
            }
            return std::make_unique< uc::gx::dx12::gpu_command_queue>(d, present_queue.Get());
        }

        auto create_swap_chain(IDXGIFactory2* factory, ID3D12CommandQueue* queue, uint32_t back_buffer_width, uint32_t back_buffer_height)
        {
            back_buffer_width   = max(back_buffer_width, 8U);
            back_buffer_height  = max(back_buffer_height, 8U);
            // Otherwise, create a new one using the same adapter as the existing Direct3D device.
            DXGI_SCALING scaling = DXGI_SCALING_STRETCH;    // DisplayMetrics::SupportHighResolutions ? DXGI_SCALING_NONE : DXGI_SCALING_STRETCH;
            DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};

            swapChainDesc.Width                 = back_buffer_width;
            swapChainDesc.Height                = back_buffer_height;
            swapChainDesc.Format                = DXGI_FORMAT_R8G8B8A8_UNORM;
            swapChainDesc.Stereo                = false;
            swapChainDesc.SampleDesc.Count      = 1;                                    // Don't use multi-sampling.
            swapChainDesc.SampleDesc.Quality    = 0;
            swapChainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            swapChainDesc.BufferCount           = 3;                                    // Use triple-buffering to minimize latency.
            swapChainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;        // All Windows Universal apps must use _FLIP_ SwapEffects
            swapChainDesc.Flags                 = 0;
            swapChainDesc.Scaling               = scaling;
            swapChainDesc.AlphaMode             = DXGI_ALPHA_MODE_IGNORE;

            winrt::com_ptr<IDXGISwapChain1> result;

            uc::gx::dx12::throw_if_failed(
                factory->CreateSwapChainForComposition(
                    queue,
                    &swapChainDesc,
                    nullptr,
                    result.put()
                )
            );

            return result.as<IDXGISwapChain4>();
        }
    }

    CompositionSwapChainResources::CompositionSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const& ctx, Windows::UI::Xaml::Controls::SwapChainPanel const& panel)
    {
        winrt::com_ptr<IResourceCreateContextNative> const native{ ctx.as<IResourceCreateContextNative>() };

        if (native)
        {
            ID3D12Device* device = native->GetDevice();

            m_resource_context = native;

            using namespace uc::gx;

            m_composition_scale_x = panel.CompositionScaleX();
            m_composition_scale_y = panel.CompositionScaleY();
            m_logical_size        = { static_cast<float>(panel.Width()), static_cast<float>(panel.Height()) };

            if (m_logical_size.Width != m_logical_size.Width)
            {
                m_logical_size.Width = 8.0f;
            }

            if (m_logical_size.Height != m_logical_size.Height)
            {
                m_logical_size.Height = 8.0f;
            }


            m_display_information = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
            auto r                = BuildSwapChainSize(m_logical_size, m_display_information, m_composition_scale_x, m_composition_scale_y);


            Microsoft::WRL::ComPtr<IDXGIFactory4> factory = dx12::create_dxgi_factory4();
            m_direct_queue        = create_command_queue(device, D3D12_COMMAND_LIST_TYPE_DIRECT);

            m_swap_chain          = create_swap_chain(factory.Get(), m_direct_queue->queue(), static_cast<uint32_t>(r.Width), static_cast<uint32_t>(r.Height));

            winrt::com_ptr<ISwapChainPanelNative> const p{ panel.as<ISwapChainPanelNative>() };
            p->SetSwapChain(m_swap_chain.get());

            auto&& rc = m_resource_context->GetResourceCreateContext();

            m_direct_command_manager    = std::make_unique<dx12::gpu_command_manager>(device, m_direct_queue.get());
            m_direct_context_allocator  = std::make_unique<dx12::gpu_command_context_allocator>(native->GetResourceCreateContext(), m_direct_command_manager.get(), m_direct_queue.get());

            m_direct_queue->increment_fence();
            m_direct_queue->increment_fence();

            m_buffer_count = 3;
            m_back_buffer.resize(3);

            for (auto i = 0U; i < m_buffer_count; ++i)
            {
                using namespace uc;

                //Recreate the back buffers
                Microsoft::WRL::ComPtr<ID3D12Resource> back_buffer;
                gx::dx12::throw_if_failed(m_swap_chain->GetBuffer(i, IID_PPV_ARGS(&back_buffer)));
                m_back_buffer[i] = std::unique_ptr<gx::dx12::gpu_back_buffer>(rc->create_back_buffer(back_buffer.Get()));
            }
        }
    }

    CompositionSwapChainResources::~CompositionSwapChainResources()
    {

    }

    void CompositionSwapChainResources::Resize(uint32_t width, uint32_t height)
    {
        for (auto i = 0U; i < m_buffer_count; ++i)
        {
            m_back_buffer[i].reset();
        }

        uc::gx::dx12::throw_if_failed(m_swap_chain->ResizeBuffers(m_buffer_count, width, height, m_swap_chain_format, m_resize_flags));

        auto&& rc = m_resource_context->GetResourceCreateContext();
        uint32_t frame = m_buffer_index;

        for (auto i = 0U; i < m_buffer_count; ++i)
        {
            using namespace uc;

            //Recreate the back buffers
            Microsoft::WRL::ComPtr<ID3D12Resource> back_buffer;
            gx::dx12::throw_if_failed(m_swap_chain->GetBuffer(i, IID_PPV_ARGS(&back_buffer)));
            m_back_buffer[frame] = std::unique_ptr<gx::dx12::gpu_back_buffer>(rc->create_back_buffer(back_buffer.Get()));

            frame++;
            frame %= m_buffer_count;
        }
    }

    void CompositionSwapChainResources::WaitForGpu()
    {
        m_direct_queue->wait_for_idle_gpu();
    }

    void CompositionSwapChainResources::WaitForFence(IFenceHandle  v)
    {
        winrt::com_ptr<IFenceHandleNative> const native{ v.as<IFenceHandleNative>() };

        auto fence = native->GetFenceHandle();

        if (fence->m_fence == m_direct_queue->fence())
        {
            m_direct_queue->wait_for_fence(fence->m_value);
        }
    }

    void CompositionSwapChainResources::InsertWaitOn(IFenceHandle  v)
    {
        winrt::com_ptr<IFenceHandleNative> const native{ v.as<IFenceHandleNative>() };
        auto fence = native->GetFenceHandle();
        m_direct_queue->insert_wait_on(*fence);
    }

    void CompositionSwapChainResources::Present()
    {
        m_swap_chain->Present(0, 0);
    }

    void CompositionSwapChainResources::Sync()
    {
        m_direct_context_allocator->sync();
    }

    void CompositionSwapChainResources::MoveToNextFrame()
    {
        m_buffer_index = m_buffer_index + 1;
        m_buffer_index = m_buffer_index % m_buffer_count;

        auto fence = m_direct_queue->increment_fence();
        m_direct_queue->wait_for_fence(fence - 2);
    }

    void CompositionSwapChainResources::SetSourceSize(uint32_t width, uint32_t height)
    {
        m_swap_chain->SetSourceSize(width, height);
    }

    void CompositionSwapChainResources::SetLogicalSize(Size2D size)
    {
        m_logical_size = size;
        auto r = BuildSwapChainSize(m_logical_size, m_display_information, m_composition_scale_x, m_composition_scale_y);
        Resize(static_cast<uint32_t>(r.Width), static_cast<uint32_t>(r.Height));
    }

    void CompositionSwapChainResources::SetCompositionScale(float scaleX, float scaleY)
    {
        m_composition_scale_x = scaleX;
        m_composition_scale_y = scaleY;

        auto r = BuildSwapChainSize(m_logical_size, m_display_information, m_composition_scale_x, m_composition_scale_y);
        Resize(static_cast<uint32_t>(r.Width), static_cast<uint32_t>(r.Height));
    }

    void CompositionSwapChainResources::SetDisplayInformation(const Windows::Graphics::Display::DisplayInformation& displayInformation)
    {
        m_display_information = displayInformation;
        auto r = BuildSwapChainSize(m_logical_size, m_display_information, m_composition_scale_x, m_composition_scale_y);
        Resize(static_cast<uint32_t>(r.Width), static_cast<uint32_t>(r.Height));
    }

    IDirectGpuCommandContext CompositionSwapChainResources::CreateDirectCommandContext()
    {
        return make<DirectGpuCommandContext>(uc::gx::dx12::create_graphics_command_context(m_direct_context_allocator.get()));
    }

    IComputeGpuCommandContext CompositionSwapChainResources::CreateComputeCommandContext()
    {
        return make<ComputeGpuCommandContext>(uc::gx::dx12::create_compute_command_context(m_direct_context_allocator.get()));
    }

    IBackBuffer CompositionSwapChainResources::BackBuffer() const
    {
        return make<BackBuffer1>(m_back_buffer[m_buffer_index].get());
    }
}
