#include "pch.h"
#include "BackBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    BackBuffer::BackBuffer(gpu_back_buffer* b) : m_back_buffer(b)
    {

    }

    GpuVirtualAddress BackBuffer::VirtualAddress() const
    {
        return { m_back_buffer->virtual_address() };
    }

    Size3D BackBuffer::Size3D() const
    {
        auto r = m_back_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
    }

    Size2D            BackBuffer::Size2D() const
    {
        auto r = m_back_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
    }

    uc::gx::dx12::gpu_back_buffer* BackBuffer::GetBackBuffer()
    {
        return m_back_buffer;
    }

    uc::gx::dx12::gpu_virtual_resource* BackBuffer::GetResource()
    {
        return m_back_buffer;
    }
   
}
