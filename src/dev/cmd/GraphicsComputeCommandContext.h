﻿#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"


#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct DirectGpuCommandContext : implements<DirectGpuCommandContext, IGraphicsComputeCommandContext, IComputeCommandContext, ICommandContext >
    {
        DirectGpuCommandContext(uc::gx::dx12::managed_graphics_compute_command_context ctx);

        IFenceHandle Submit();
        void SubmitAndWaitToExecute();
        void TransitionResource(IVirtualResource r, ResourceState old_state, ResourceState new_state);
		void CopyResource(IVirtualResource d, IVirtualResource s);


        void Dispatch(uint32_t x, uint32_t y, uint32_t z) {}
		void Draw(uint32_t vertex_count, uint32_t vertex_offset);
		void DrawInstanced(uint32_t vertexCountPerInstance, uint32_t instanceCount, uint32_t startVertexLocation, uint32_t startInstanceLocation);
		void DrawIndexed(uint32_t indexCount, uint32_t startIndexLocation, int32_t baseVertexLocation);
		void DrawIndexedInstanced(uint32_t indexCountPerInstance, uint32_t instanceCount, uint32_t startIndexLocation, int32_t baseVertexLocation, uint32_t startInstanceLocation);


		void SetDescriptorHeaps();
        void SetComputePipelineStateObject(const ComputePipelineState& s) {}
		void SetGraphicsPipelineStateObject(const GraphicsPipelineState& s);

		void SetViewPort(const ViewPort& vp);
		void SetScissorRectangle(const Rectangle2D& r);
		void SetPrimitiveTopology(const PrimitiveTopology& t);

		void SetIndexBuffer(const IndexBufferView& view);
		void SetVertexBuffer(uint32_t slot, const VertexBufferView& view);

        void SetComputeUAVBuffer(uint32_t slot, IVirtualResource r);

		void Clear(const SwapChainBuffer& b);
		void Clear(const IColorBuffer& b);
		void Clear(const IDepthBuffer& b);
		void Clear(const IDepthStencilBuffer& b);

		void SetRenderTargetSimple(const IColorBuffer& b);
		void SetRenderTargetSimple(const SwapChainBuffer& b);
		void SetRenderTargetSimple(const IDepthBuffer& d);
		void SetRenderTargetSimple(const IDepthStencilBuffer& d);

		void SetRenderTarget(const IColorBuffer& b, const IDepthBuffer& d);
		void SetRenderTarget(const IColorBuffer& b, const IDepthStencilBuffer& d);
		void SetRenderTarget(const SwapChainBuffer& b, const IDepthBuffer& d);
		void SetRenderTarget(const SwapChainBuffer& b, const IDepthStencilBuffer& d);

		private:
        uc::gx::dx12::managed_graphics_compute_command_context m_ctx;
   };  
}

