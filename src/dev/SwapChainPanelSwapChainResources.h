#pragma once

#include "ResourceCreateContext.g.h"
#include "SwapChainPanelSwapChainResources.g.h"

#include <d3d12.h>
#include <wrl/client.h>

#include <uc/gx/dx12/dx12.h>


namespace winrt::UniqueCreator::Graphics::implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT<SwapChainPanelSwapChainResources >
    {
        SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const& ctx, Windows::UI::Xaml::Controls::SwapChainPanel const & panel);

        
        private:

        std::unique_ptr<uc::gx::dx12::gpu_command_queue> m_direct_queue;
        winrt::com_ptr<IDXGISwapChain4>                  m_swap_chain;
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT < SwapChainPanelSwapChainResources, winrt::UniqueCreator::Graphics::implementation::SwapChainPanelSwapChainResources >
    {

    };
}
