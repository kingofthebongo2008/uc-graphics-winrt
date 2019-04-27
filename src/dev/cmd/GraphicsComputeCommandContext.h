#pragma once

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

        void Copy() {}
        void Dispatch(uint32_t x, uint32_t y, uint32_t z) {}
		void Draw(uint32_t vertex_count, uint32_t vertex_offset);

		void SetDescriptorHeaps();
        void SetComputePipelineStateObject(const ComputePipelineState& s) {}
		void SetGraphicsPipelineStateObject(const GraphicsPipelineState& s);

		void SetViewPort(const ViewPort& vp);
		void SetScissorRectangle(const Rectangle2D& r);
		void SetPrimitiveTopology(const PrimitiveTopology& t);

        void SetComputeUAVBuffer(uint32_t slot, IVirtualResource r);

		void Clear(const SwapChainBuffer& b);
		void Clear(const IColorBuffer& b);
		void Clear(const IDepthBuffer& b);
		void Clear(const IDepthStencilBuffer& b);

		void SetRenderTargetSimple(const IColorBuffer& b);
		void SetRenderTargetSimple(const SwapChainBuffer& b);

		void SetRenderTarget(const IColorBuffer& b, const IDepthBuffer& d);
		void SetRenderTarget(const IColorBuffer& b, const IDepthStencilBuffer& d);

		void SetRenderTarget(const SwapChainBuffer& b, const IDepthBuffer& d);
		void SetRenderTarget(const SwapChainBuffer& b, const IDepthStencilBuffer& d);

		void SetDepth(const IDepthBuffer& d);
		void SetDepth(const IDepthStencilBuffer& d);

		private:
        uc::gx::dx12::managed_graphics_compute_command_context m_ctx;
   };  
}

