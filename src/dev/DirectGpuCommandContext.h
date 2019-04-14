#pragma once

#include "winrt/UniqueCreator.Graphics.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct DirectGpuCommandContext : implements<DirectGpuCommandContext, IGraphicsGpuCommandContext, IComputeGpuCommandContext, ICopyGpuCommandContext, IGpuCommandContext >
    {
        DirectGpuCommandContext(uc::gx::dx12::managed_graphics_compute_command_context ctx);

        IFenceHandle Submit();
        void SubmitAndWaitToExecute();
        void TransitionResource(IGpuVirtualResource r, ResourceState old_state, ResourceState new_state);

        void Copy() {}
        void Dispatch(uint32_t x, uint32_t y, uint32_t z) {}
        void Draw() {}

        void SetPSO(const ComputePipelineState& s) {}
        void SetComputeUAVBuffer(uint32_t slot, IGpuVirtualResource r);

        void Clear(IBackBuffer b);

        private:

        uc::gx::dx12::managed_graphics_compute_command_context m_ctx;
   };  
}

