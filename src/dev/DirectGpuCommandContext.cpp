#include "pch.h"
#include "DirectGpuCommandContext.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    DirectGpuCommandContext::DirectGpuCommandContext(uc::gx::dx12::managed_graphics_command_context ctx) : m_ctx(std::move(ctx))
    {

    }
}
