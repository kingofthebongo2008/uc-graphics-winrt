#pragma once

#include "DirectGpuCommandContext.g.h"
#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct DirectGpuCommandContext : DirectGpuCommandContextT<DirectGpuCommandContext >
    {
        DirectGpuCommandContext(uc::gx::dx12::managed_graphics_command_context ctx);

        private:
        uc::gx::dx12::managed_graphics_command_context m_ctx;
   };  
}

