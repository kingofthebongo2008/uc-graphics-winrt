﻿#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.ResourceCreateContext.h"
#include "gpu/ColorBuffer.h"
#include "gpu/DepthBuffer.h"
#include "gpu/DepthStencilBuffer.h"
#include "gpu/ByteAddressBuffer.h"
#include "gpu/UploadBuffer.h"
#include "gpu/Texture2D.h"

#include "uc/gx/dx12/dx12.h"



namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    ID3D12Device* ResourceCreateContext::GetDevice( ) noexcept
    {
        return m_device.get();
    }

    uc::gx::dx12::gpu_resource_create_context* ResourceCreateContext::GetResourceCreateContext() noexcept
    {
        return m_ctx.get();
    }

    ResourceCreateContext::ResourceCreateContext()
    {
//#if defined(_DEBUG)
        {
            Microsoft::WRL::ComPtr<ID3D12Debug1>                        m_debug;
            auto hresult = D3D12GetDebugInterface(IID_PPV_ARGS(&m_debug));
            if (SUCCEEDED(hresult))
            {
                m_debug->EnableDebugLayer();

                //todo: check intel driver, which failes with the gpu validation
                m_debug->SetEnableGPUBasedValidation(TRUE);
                m_debug->SetEnableSynchronizedCommandQueueValidation(TRUE);
            }
        }
//#endif


        HRESULT r = D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_12_1, __uuidof(ID3D12Device4), (void**)m_device.put());

        if (r == S_OK)
        {
            m_ctx = std::make_unique<uc::gx::dx12::gpu_resource_create_context>(m_device.get());
        }
    }

	Gpu::FrameColorBuffer ResourceCreateContext::CreateFrameColorBuffer(uint32_t width, uint32_t height, GraphicsFormat		format, ResourceState state)
	{
		return make<FrameColorBuffer>(create_frame_color_buffer(m_ctx.get(), width, height, static_cast<DXGI_FORMAT>(format), static_cast<D3D12_RESOURCE_STATES>(state)));
	}

	Gpu::FrameDepthBuffer ResourceCreateContext::CreateFrameDepthBuffer(uint32_t width, uint32_t height, DepthBufferFormat	format, ResourceState state)
	{
		return make<FrameDepthBuffer>(create_frame_depth_buffer(m_ctx.get(), width, height, static_cast<DXGI_FORMAT>(format)));// , static_cast<D3D12_RESOURCE_STATES>(state)));
	}

	Gpu::FrameDepthStencilBuffer ResourceCreateContext::CreateFrameDepthStencilBuffer(uint32_t width, uint32_t height, DepthStencilBufferFormat format, ResourceState state)
	{
		throw hresult_not_implemented();
	}

	Gpu::ViewColorBuffer ResourceCreateContext::CreateViewColorBuffer(uint32_t width, uint32_t height, GraphicsFormat	format)
	{
		return make<ViewColorBuffer>(std::unique_ptr<gpu_view_color_buffer>(m_ctx->create_view_color_buffer(width, height, static_cast<DXGI_FORMAT>(format))));
	}

	Gpu::ViewDepthBuffer ResourceCreateContext::CreateViewDepthBuffer(uint32_t width, uint32_t height, DepthBufferFormat format)
	{
		return make<ViewDepthBuffer>(std::unique_ptr<gpu_view_depth_buffer>(m_ctx->create_view_depth_buffer(width, height, static_cast<DXGI_FORMAT>(format))));
	}

	Gpu::ViewDepthStencilBuffer ResourceCreateContext::CreateViewDepthStencilBuffer(uint32_t width, uint32_t height, DepthStencilBufferFormat format)
	{
		throw hresult_not_implemented();
	}

    void ResourceCreateContext::Sync()
    {
        m_ctx->sync();
    }

    void ResourceCreateContext::ResetViewDependentResources()
    {
        m_ctx->reset_view_dependent_resources();
    }

	Gpu::ByteAddressBuffer	ResourceCreateContext::CreateByteAddressBuffer(uint32_t size, ResourceState const& initialState)
	{
		return make<ByteAddressBuffer>(create_byteaddress_buffer(m_ctx.get(), size , static_cast<D3D12_RESOURCE_STATES>(initialState)));
	}

	Gpu::UploadBuffer ResourceCreateContext::CreateUploadBuffer(uint32_t size)
	{
		return make<UploadBuffer>(create_upload_buffer(m_ctx.get(), size));
	}

	Gpu::Texture2D ResourceCreateContext::CreateTexture2D(uint32_t width, uint32_t height, uint32_t mips, GraphicsFormat const& format, ResourceState const& initialState)
	{
		return make<Texture2D>(create_texture_2d(m_ctx.get(), width, height, static_cast<DXGI_FORMAT>(format), static_cast<D3D12_RESOURCE_STATES>(initialState)));
	}
}
