#include "pch.h"
#include "DepthBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    FrameDepthBuffer::FrameDepthBuffer(std::unique_ptr<gpu_frame_depth_buffer> b) : m_depth_buffer(std::move(b))
    {

    }

    GpuVirtualAddress FrameDepthBuffer::VirtualAddress() const
    {
        return { m_depth_buffer->virtual_address() };
    }

    Size3D FrameDepthBuffer::Size3D() const
    {
        auto r = m_depth_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
    }

    Size2D            FrameDepthBuffer::Size2D() const
    {
        auto r = m_depth_buffer->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
    }

    uc::gx::dx12::gpu_depth_buffer* FrameDepthBuffer::GetDepthBuffer()
    {
		return m_depth_buffer.get();
    }

    uc::gx::dx12::gpu_virtual_resource* FrameDepthBuffer::GetResource()
    {
		return m_depth_buffer.get();
    }

	////////////////////////////////////

	ViewDepthBuffer::ViewDepthBuffer(std::unique_ptr<gpu_view_depth_buffer> b) : m_depth_buffer( std::move(b))
	{

	}

	GpuVirtualAddress ViewDepthBuffer::VirtualAddress() const
	{
		return { m_depth_buffer->virtual_address() };
	}

	Size3D ViewDepthBuffer::Size3D() const
	{
		auto r = m_depth_buffer->desc();
		return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
	}

	Size2D            ViewDepthBuffer::Size2D() const
	{
		auto r = m_depth_buffer->desc();
		return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
	}

	uc::gx::dx12::gpu_depth_buffer* ViewDepthBuffer::GetDepthBuffer()
	{
		return m_depth_buffer.get();
	}

	uc::gx::dx12::gpu_virtual_resource* ViewDepthBuffer::GetResource()
	{
		return m_depth_buffer.get();
	}
   
}
