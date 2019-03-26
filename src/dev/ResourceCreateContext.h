﻿#pragma once

#include "ResourceCreateContext.g.h"
#include "IResourceCreateContextNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext, IResourceCreateContextNative >
    {
        ResourceCreateContext();
        
        //IResourceCreateContextNative
        ID3D12Device* GetDevice( ) noexcept;

        uc::gx::dx12::gpu_resource_create_context* GetResourceCreateContext() noexcept;

        //ResourceCreateContext
        //UniqueCreator::Graphics::DirectQueue CreateDirectQueue();

        void Sync();
        void ResetViewDependentResources();

    private:
        winrt::com_ptr<ID3D12Device>                               m_device;
        std::unique_ptr<uc::gx::dx12::gpu_resource_create_context> m_ctx;
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ResourceCreateContext : ResourceCreateContextT < ResourceCreateContext, winrt::UniqueCreator::Graphics::implementation::ResourceCreateContext >
    {

    };
}

