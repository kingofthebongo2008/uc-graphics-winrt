#pragma once

#include "SwapChainPanelSwapChainResources.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT<SwapChainPanelSwapChainResources>
    {
        SwapChainPanelSwapChainResources() = delete;
        SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const& ctx, Windows::UI::Xaml::Controls::SwapChainPanel const& panel);

        HRESULT Resize(uint32_t width, uint32_t height);
        HRESULT WaitForGpu();
        HRESULT WaitForFence(UniqueCreator::Graphics::IFenceHandle const& v);
        HRESULT InsertWaitOn(UniqueCreator::Graphics::IFenceHandle const& v);
        HRESULT Present();
        HRESULT Sync();
        HRESULT MoveToNextFrame();
        HRESULT SetSourceSize(uint32_t width, uint32_t height);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct SwapChainPanelSwapChainResources : SwapChainPanelSwapChainResourcesT<SwapChainPanelSwapChainResources, implementation::SwapChainPanelSwapChainResources>
    {
    };
}
