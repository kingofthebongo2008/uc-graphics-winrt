#pragma once

#include "UniqueCreator.Graphics.Gpu.ResourceCreateContext.g.h"
#include "IResourceCreateContextNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext, IResourceCreateContextNative >
    {
        ResourceCreateContext();
        
        //IResourceCreateContextNative
        ID3D12Device* GetDevice( ) noexcept;

        uc::gx::dx12::gpu_resource_create_context* GetResourceCreateContext() noexcept;

        
		Gpu::FrameColorBuffer        CreateFrameColorBuffer(uint32_t width, uint32_t height, GraphicsFormat					 format);
		Gpu::FrameDepthBuffer        CreateFrameDepthBuffer(uint32_t width, uint32_t height, DepthBufferFormat				 format);
		Gpu::FrameDepthStencilBuffer CreateFrameDepthStencilBuffer(uint32_t width, uint32_t height, DepthStencilBufferFormat format);

		Gpu::ViewColorBuffer        CreateViewColorBuffer(uint32_t width, uint32_t height, GraphicsFormat format);
		Gpu::ViewDepthBuffer        CreateViewDepthBuffer(uint32_t width, uint32_t height, DepthBufferFormat format);
		Gpu::ViewDepthStencilBuffer CreateViewDepthStencilBuffer(uint32_t width, uint32_t height, DepthStencilBufferFormat format);

        void Sync();
        void ResetViewDependentResources();

    private:
        winrt::com_ptr<ID3D12Device>                               m_device;
        std::unique_ptr<uc::gx::dx12::gpu_resource_create_context> m_ctx;
   };  
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct ResourceCreateContext : ResourceCreateContextT < ResourceCreateContext, implementation::ResourceCreateContext >
    {

    };
}

