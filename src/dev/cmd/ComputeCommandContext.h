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

		void SetComputeUAVBuffer(uint32_t slot, IVirtualResource r);

        void Copy() {}

        void Dispatch(uint32_t x, uint32_t y, uint32_t z);
        void SetComputePipelineStateObject(const ComputePipelineState& s);

		void SetDescriptorHeaps();

        private:

        uc::gx::dx12::managed_compute_command_context m_ctx;
   };  
}

