#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct ComputeCommandContext : implements<ComputeCommandContext, IComputeCommandContext, ICommandContext >
    {
        ComputeCommandContext(uc::gx::dx12::managed_compute_command_context ctx);

        IFenceHandle Submit();
        void SubmitAndWaitToExecute();
        void TransitionResource(IVirtualResource r, ResourceState old_state, ResourceState new_state);
		void SetDescriptorHeaps();


		void SetComputePipelineStateObject(const ComputePipelineState& s);
		void Dispatch(uint32_t x, uint32_t y, uint32_t z);
		void SetComputeSRVBuffer(uint32_t rootIndex, const IVirtualResource& r);
		void SetComputeUAVBuffer(uint32_t rootIndex, const IVirtualResource& r);
		void SetComputeConstantBuffer(uint32_t rootIndex, const GpuVirtualAddress r);

		void SetComputeConstantBufferData(uint32_t rootIndex, const Windows::Foundation::Collections::IVector<uint8_t>& buffer);
		void SetComputeSRV(uint32_t rootIndex, uint32_t offset, const IShaderResourceView& r);
		void SetComputeUAV(uint32_t rootIndex, uint32_t offset, const IUnorderedAccessView& r);
		void SetComputeRootConstant(uint32_t rootIndex, uint32_t offset, uint32_t constant);

        private:

        uc::gx::dx12::managed_compute_command_context m_ctx;
   };  
}

