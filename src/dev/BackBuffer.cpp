#include "pch.h"
#include "BackBuffer.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    GpuVirtualAddress BackBuffer::VirtualAddress() const
    {
        return {};
    }

    Size3D            BackBuffer::Size3D() const
    {
        return {};
    }

    Size2D            BackBuffer::Size2D() const
    {
        return {};
    }

    uc::gx::dx12::gpu_back_buffer* BackBuffer::GetBackBuffer()
    {
        return nullptr;
    }

    uc::gx::dx12::gpu_virtual_resource* BackBuffer::GetResource()
    {
        return nullptr;
    }
   
}
