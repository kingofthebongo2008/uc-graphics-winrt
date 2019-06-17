#include "pch.h"
#include "winrt.h"
#include "ColorBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	FrameColorBuffer::FrameColorBuffer(managed_gpu_frame_color_buffer b) : m_color_buffer(std::move(b))
    {

    }

    GpuVirtualAddress FrameColorBuffer::VirtualAddress() const
    {
        return { m_color_buffer->virtual_address() };
    }

	CpuDescriptorHandle FrameColorBuffer::SRV() const
	{
		D3D12_CPU_DESCRIPTOR_HANDLE h = m_color_buffer->srv();
		return { h.ptr };
	}

	CpuDescriptorHandle FrameColorBuffer::UAV() const
	{
		D3D12_CPU_DESCRIPTOR_HANDLE h = m_color_buffer->uav();
		return { h.ptr };
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
		return m_color_buffer.get();
    }

    uc::gx::dx12::gpu_virtual_resource* FrameColorBuffer::GetResource()
    {
		return m_color_buffer.get();
    }

	//////////////////////
	ViewColorBuffer::ViewColorBuffer(std::unique_ptr<gpu_view_color_buffer> b) : m_color_buffer(std::move(b))
	{

	}

	GpuVirtualAddress ViewColorBuffer::VirtualAddress() const
	{
		return { m_color_buffer->virtual_address() };
	}

	CpuDescriptorHandle ViewColorBuffer::SRV() const
	{
		D3D12_CPU_DESCRIPTOR_HANDLE h = m_color_buffer->srv();
		return { h.ptr };
	}

	CpuDescriptorHandle ViewColorBuffer::UAV() const
	{
		D3D12_CPU_DESCRIPTOR_HANDLE h = m_color_buffer->uav();
		return { h.ptr };
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
		return m_color_buffer.get();
	}

	uc::gx::dx12::gpu_virtual_resource* ViewColorBuffer::GetResource()
	{
		return m_color_buffer.get();
	}
   
}
