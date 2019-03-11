#pragma once

#include "ResourceCreateContext.g.h"
#include "SwapChainPanelSwapChainResources.g.h"


namespace winrt::UniqueCreator::Graphics::implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT<SwapChainPanelSwapChainResources >
    {
        SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const& ctx, Windows::UI::Xaml::Controls::SwapChainPanel const & panel);

        HRESULT f();
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT < SwapChainPanelSwapChainResources, winrt::UniqueCreator::Graphics::implementation::SwapChainPanelSwapChainResources >
    {

    };
}
