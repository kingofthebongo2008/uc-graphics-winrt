#pragma once

#include "ResourceCreateContext.g.h"
#include "IResourceCreateContextNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext, IResourceCreateContextNative >
    {
        ResourceCreateContext();// = default;
        
        hstring Text();

        HRESULT Call() noexcept;
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ResourceCreateContext : ResourceCreateContextT < ResourceCreateContext, winrt::UniqueCreator::Graphics::implementation::ResourceCreateContext >
    {

    };
}
