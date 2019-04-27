#include "pch.h"
#include "ColorBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    FrameColorBuffer::FrameColorBuffer(gpu_color_buffer* b) : m_color_buffer(b)
    {

    }

    GpuVirtualAddress FrameColorBuffer::VirtualAddress() const
    {
        return { m_color_buffer->virtual_address() };
    }

    Size3D FrameColorBuffer::Size3D() const
    {
        auto r = m_color_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
    }

    Size2D            FrameColorBuffer::Size2D() const
    {
        auto r = m_color_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
    }

    uc::gx::dx12::gpu_color_buffer* FrameColorBuffer::GetColorBuffer()
    {
        return m_color_buffer;
    }

    uc::gx::dx12::gpu_virtual_resource* FrameColorBuffer::GetResource()
    {
        return m_color_buffer;
    }

	//////////////////////
	ViewColorBuffer::ViewColorBuffer(gpu_color_buffer* b) : m_color_buffer(b)
	{

	}

	GpuVirtualAddress ViewColorBuffer::VirtualAddress() const
	{
		return { m_color_buffer->virtual_address() };
	}

	Size3D ViewColorBuffer::Size3D() const
	{
		auto r = m_color_buffer->desc();
		return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
	}

	Size2D            ViewColorBuffer::Size2D() const
	{
		auto r = m_color_buffer->desc();
		return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
	}

	uc::gx::dx12::gpu_color_buffer* ViewColorBuffer::GetColorBuffer()
	{
		return m_color_buffer;
	}

	uc::gx::dx12::gpu_virtual_resource* ViewColorBuffer::GetResource()
	{
		return m_color_buffer;
	}
   
}
