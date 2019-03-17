#pragma once

#include "winrt/UniqueCreator.Graphics.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct DirectGpuCommandContext : implements<DirectGpuCommandContext, IDirectGpuCommandContext, IComputeGpuCommandContext, ICopyGpuCommandContext, IGpuCommandContext >
    {
        DirectGpuCommandContext(uc::gx::dx12::managed_graphics_command_context ctx);

        IFenceHandle Submit();
        void SubmitAndWaitToExecute();
        void TransitionResource(IGpuVirtualResource r, ResourceState old_state, ResourceState new_state);

        void Copy() {}
        void Dispatch() {}
        void Draw() {}

        void Clear(IBackBuffer b);

        private:

        uc::gx::dx12::managed_graphics_command_context m_ctx;
   };  
}

