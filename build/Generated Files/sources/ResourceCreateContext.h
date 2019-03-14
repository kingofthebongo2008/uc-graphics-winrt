#pragma once

#include "ResourceCreateContext.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext>
    {
        ResourceCreateContext() = default;

        UniqueCreator::Graphics::DirectQueue CreateDirectQueue();
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext, implementation::ResourceCreateContext>
    {
    };
}
