#pragma once

#include "winrt/UniqueCreator.Graphics.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ComputeGpuCommandContext : implements<ComputeGpuCommandContext, IComputeGpuCommandContext, ICopyGpuCommandContext, IGpuCommandContext >
    {
        ComputeGpuCommandContext(uc::gx::dx12::managed_compute_command_context ctx);

        IFenceHandle Submit();
        void SubmitAndWaitToExecute();
        void TransitionResource(IGpuVirtualResource r, ResourceState old_state, ResourceState new_state);

        void Copy() {}

        void Dispatch(uint32_t x, uint32_t y, uint32_t z);
        void SetPSO(const ComputePipelineState& s);


        private:

        uc::gx::dx12::managed_compute_command_context m_ctx;
   };  
}

