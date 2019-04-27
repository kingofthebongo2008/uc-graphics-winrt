﻿#include "pch.h"
#include "GraphicsComputeCommandContext.h"
#include "UniqueCreator.Graphics.Gpu.FenceHandle.h"

#include "IGpuVirtualResourceNative.h"
#include "IGraphicsPipelineStateNative.h"
#include "IComputePipelineStateNative.h"

#include "IBackBufferNative.h"
#include "IDepthBufferNative.h"


namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    DirectGpuCommandContext::DirectGpuCommandContext(uc::gx::dx12::managed_graphics_compute_command_context ctx) : m_ctx(std::move(ctx))
    {

    }

    IFenceHandle DirectGpuCommandContext::Submit()
    {
        auto r = make<FenceHandle>(m_ctx->submit(uc::gx::dx12::gpu_command_context::do_not_wait_to_execute));
        m_ctx.reset();
        return r;
    }

    void DirectGpuCommandContext::SubmitAndWaitToExecute()
    {
        m_ctx->submit(uc::gx::dx12::gpu_command_context::wait_to_execute);
        m_ctx.reset();
    }
    void DirectGpuCommandContext::TransitionResource(IVirtualResource r, ResourceState old_state, ResourceState new_state)
    {
        com_ptr<IGpuVirtualResourceNative> r0(r.as<IGpuVirtualResourceNative>());

        m_ctx->transition_resource(r0->GetResource(), static_cast<D3D12_RESOURCE_STATES>(old_state), static_cast<D3D12_RESOURCE_STATES>(new_state));
    }

    void DirectGpuCommandContext::Clear(const SwapChainBuffer& b)
    {
        com_ptr<IBackBufferNative> r0(b.as<IBackBufferNative>());
        m_ctx->clear(r0->GetBackBuffer());
    }

	void DirectGpuCommandContext::Clear(const IColorBuffer& b)
	{
		com_ptr<IColorBufferNative> r0(b.as<IColorBufferNative>());
		m_ctx->clear(r0->GetColorBuffer());
	}

	void DirectGpuCommandContext::Clear(const IDepthBuffer& b)
	{
		com_ptr<IDepthBufferNative> r0(b.as<IDepthBufferNative>());
		m_ctx->clear(r0->GetDepthBuffer());
	}

	void DirectGpuCommandContext::Clear(const IDepthStencilBuffer& b)
	{
		com_ptr<IDepthStencilBufferNative> r0(b.as<IDepthStencilBufferNative>());
		m_ctx->clear(r0->GetDepthStencilBuffer());
	}


    void DirectGpuCommandContext::SetComputeUAVBuffer(uint32_t slot, IVirtualResource r)
    {
        com_ptr<IGpuVirtualResourceNative> r0(r.as<IGpuVirtualResourceNative>());
        m_ctx->set_compute_uav_buffer(slot, r0->GetResource());
    }

	void DirectGpuCommandContext::SetGraphicsPipelineStateObject(const GraphicsPipelineState& s)
	{
		com_ptr<IGraphicsPipelineStateNative> s0(s.as<IGraphicsPipelineStateNative>());
		m_ctx->set_pso(s0->GetPipelineState());
	}

	void DirectGpuCommandContext::Draw(uint32_t vertex_count, uint32_t vertex_offset)
	{
		m_ctx->draw(vertex_count, vertex_offset);
	}

	void DirectGpuCommandContext::SetDescriptorHeaps()
	{
		m_ctx->set_descriptor_heaps();
	}

	void DirectGpuCommandContext::SetPrimitiveTopology(const PrimitiveTopology& t)
	{
		m_ctx->set_primitive_topology(static_cast<D3D12_PRIMITIVE_TOPOLOGY>(t));
	}

	void DirectGpuCommandContext::SetViewPort(const ViewPort& vp)
	{
		D3D12_VIEWPORT v = {};

		v.Height	= vp.Height;
		v.MaxDepth	= vp.MaxDepth;
		v.MinDepth	= vp.MinDepth;
		v.TopLeftX	= vp.TopLeftX;
		v.TopLeftY	= vp.TopLeftY;
		v.Width		= vp.Width;
		m_ctx->set_view_port(v);
	}

	void DirectGpuCommandContext::SetScissorRectangle(const Rectangle2D& rp)
	{
		D3D12_RECT r = {};

		r.bottom = rp.Bottom;
		r.left = rp.Left;
		r.right = rp.Right;
		r.top = rp.Top;

		m_ctx->set_scissor_rectangle(r);
	}

	void DirectGpuCommandContext::SetRenderTargetSimple(const SwapChainBuffer& b)
	{
		com_ptr<IBackBufferNative> r0(b.as<IBackBufferNative>());
		m_ctx->set_render_target(r0->GetBackBuffer());
	}

	void DirectGpuCommandContext::SetRenderTargetSimple(const IColorBuffer& b)
	{
		com_ptr<IColorBufferNative> r0(b.as<IColorBufferNative>());
		m_ctx->set_render_target(r0->GetColorBuffer());
	}

	void DirectGpuCommandContext::SetRenderTarget(const IColorBuffer& b, const IDepthBuffer& d)
	{

	
	}

	void DirectGpuCommandContext::SetRenderTarget(const IColorBuffer& b, const IDepthStencilBuffer& d)
	{

	}

	void DirectGpuCommandContext::SetRenderTarget(const SwapChainBuffer& b, const IDepthBuffer& d)
	{

	}

	void DirectGpuCommandContext::SetRenderTarget(const SwapChainBuffer& b, const IDepthStencilBuffer& d)
	{

	}

	void DirectGpuCommandContext::SetDepth(const IDepthBuffer& d)
	{

	}
	
	void DirectGpuCommandContext::SetDepth(const IDepthStencilBuffer& d)
	{

	}
}
