#include "pch.h"
#include "winrt.h"
#include "DepthStencilBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	FrameDepthStencilBuffer::FrameDepthStencilBuffer(gpu_depth_stencil_buffer* b) : m_depth_buffer(b)
	{

	}

	GpuVirtualAddress FrameDepthStencilBuffer::VirtualAddress() const
	{
		return { m_depth_buffer->virtual_address() };
	}

	Size3D FrameDepthStencilBuffer::Size3D() const
	{
		auto r = m_depth_buffer->desc();
		return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
	}

	Size2D            FrameDepthStencilBuffer::Size2D() const
	{
		auto r = m_depth_buffer->desc();
		return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
	}

	uc::gx::dx12::gpu_depth_stencil_buffer* FrameDepthStencilBuffer::GetDepthStencilBuffer()
	{
		return m_depth_buffer;
	}

	uc::gx::dx12::gpu_virtual_resource* FrameDepthStencilBuffer::GetResource()
	{
		return m_depth_buffer;
	}

	///////////////////////////////////


    ViewDepthStencilBuffer::ViewDepthStencilBuffer(gpu_depth_stencil_buffer* b) : m_depth_buffer(b)
    {

    }

    GpuVirtualAddress ViewDepthStencilBuffer::VirtualAddress() const
    {
        return { m_depth_buffer->virtual_address() };
    }

    Size3D ViewDepthStencilBuffer::Size3D() const
    {
        auto r = m_depth_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
    }

    Size2D            ViewDepthStencilBuffer::Size2D() const
    {
        auto r = m_depth_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
    }

    uc::gx::dx12::gpu_depth_stencil_buffer* ViewDepthStencilBuffer::GetDepthStencilBuffer()
    {
        return m_depth_buffer;
    }

    uc::gx::dx12::gpu_virtual_resource* ViewDepthStencilBuffer::GetResource()
    {
        return m_depth_buffer;
    }
   
}
