#pragma once

#include "ResourceCreateContext.g.h"
#include "SwapChainPanelSwapChainResources.g.h"
#include "IResourceCreateContextNative.h"

#include <d3d12.h>
#include <wrl/client.h>

#include <uc/gx/dx12/dx12.h>


namespace winrt::UniqueCreator::Graphics::implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT<SwapChainPanelSwapChainResources >
    {

        SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const& ctx, Windows::UI::Xaml::Controls::SwapChainPanel const & panel);

        HRESULT Resize(uint32_t width, uint32_t height);
        HRESULT WaitForGpu();
        HRESULT WaitForFence( IFenceHandle v);
        HRESULT InsertWaitOn( IFenceHandle v);
        HRESULT Present();
        HRESULT Sync();
        HRESULT MoveToNextFrame();
        HRESULT SetSourceSize(uint32_t width, uint32_t height);


        HRESULT SetCompositionScale(float scaleX, float scaleY);
        HRESULT SetLogicalSize(Size2D size);
        HRESULT SetDisplayInformation(const Windows::Graphics::Display::DisplayInformation& displayInformation);
        
        private:


        std::unique_ptr<uc::gx::dx12::gpu_command_queue> m_direct_queue;
        winrt::com_ptr<IDXGISwapChain4>                  m_swap_chain;

        std::unique_ptr<uc::gx::dx12::gpu_command_manager>                  m_direct_command_manager;
        std::unique_ptr<uc::gx::dx12::gpu_command_context_allocator>        m_direct_context_allocator;

        
        std::vector< std::unique_ptr< uc::gx::dx12::gpu_back_buffer > >     m_back_buffer;
        winrt::com_ptr<IResourceCreateContextNative>                        m_resource_context;

        DXGI_FORMAT                                                         m_swap_chain_format = DXGI_FORMAT_R8G8B8A8_UNORM;
        uint32_t                                                            m_resize_flags      = 0;
        uint32_t                                                            m_buffer_count      = 0;
        uint32_t                                                            m_buffer_index      = 0;


        float                                                               m_composition_scale_x = 1.0f;
        float                                                               m_composition_scale_y = 1.0f;
        Size2D                                                              m_logical_size = { 1, 1 };

        Windows::Graphics::Display::DisplayInformation                      m_display_information = nullptr;
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT < SwapChainPanelSwapChainResources, winrt::UniqueCreator::Graphics::implementation::SwapChainPanelSwapChainResources >
    {

    };
}
