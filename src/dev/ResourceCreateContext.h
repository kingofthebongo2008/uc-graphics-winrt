#pragma once

#include "UniqueCreator/ResourceCreateContext.g.h"

namespace winrt::UniqueCreator::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<Button>
    {
        ResourceCreateContext() = default;

        HRESULT SetSwapChain(IDXGISwapChain *swapChain);
    };
}

namespace winrt::Component::factory_implementation
{
    struct ResourceCreateContext : ButtonT<ResourceCreateContext, implementation::ResourceCreateContext>
    {

    };
}
