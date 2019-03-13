#include "pch.h"
#include "SwapChainPanelSwapChainResources.h"
#include "IResourceCreateContextNative.h"

#include <uc/gx/dx12/dx12.h>

#include <dxgi1_6.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
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

    SwapChainPanelSwapChainResources::SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const & ctx, Windows::UI::Xaml::Controls::SwapChainPanel const & panel)
    {
        winrt::com_ptr<IResourceCreateContextNative> const native{ ctx.as<IResourceCreateContextNative>() };

        if (native)
        {
            winrt::com_ptr<ID3D12Device> device;
            HRESULT hr = native->GetDevice(device.put());

            if (SUCCEEDED(hr))
            {
                Microsoft::WRL::ComPtr<IDXGIFactory4> factory = uc::gx::dx12::create_dxgi_factory4();
                m_direct_queue  = create_command_queue(device.get(), D3D12_COMMAND_LIST_TYPE_DIRECT);
                m_swap_chain    = create_swap_chain(factory.Get(), m_direct_queue->queue(), panel.Width(), panel.Height());

                winrt::com_ptr<ISwapChainPanelNative> const p{ panel.as<ISwapChainPanelNative>() };
                p->SetSwapChain(m_swap_chain.get());
            }
        }
    }
}
