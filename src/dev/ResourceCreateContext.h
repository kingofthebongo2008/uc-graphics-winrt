#pragma once

#include "ResourceCreateContext.g.h"
#include "IResourceCreateContextNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext, IResourceCreateContextNative >
    {
        ResourceCreateContext();
        
        hstring Text();

        HRESULT __stdcall GetDevice( ID3D12Device** d) noexcept;

    private:
        winrt::com_ptr<ID3D12Device> m_device;
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ResourceCreateContext : ResourceCreateContextT < ResourceCreateContext, winrt::UniqueCreator::Graphics::implementation::ResourceCreateContext >
    {

    };
}
