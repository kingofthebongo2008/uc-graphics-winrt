#include "pch.h"
#include "winrt.h"
#include "Texture2D.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	Texture2D::Texture2D(managed_gpu_texture_2d g) : m_texture( std::move(g))
	{

	}

    void Texture2D::Dummy1()
    {
        throw hresult_not_implemented();
    }

    GpuVirtualAddress Texture2D::VirtualAddress() const
    {
        return { m_texture->virtual_address() };
    }

    Size3D Texture2D::Size3D() const
    {
        auto r = m_texture->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height), static_cast<float>(r.DepthOrArraySize) };
    }

    Size2D Texture2D::Size2D() const
    {
        auto r = m_texture->desc();
        return { static_cast<float>(r.Width), static_cast<float>(r.Height) };
    }

	CpuDescriptorHandle Texture2D::SRV() const
	{
		D3D12_CPU_DESCRIPTOR_HANDLE h = m_texture->srv();
		return { h.ptr };
	}

    uc::gx::dx12::gpu_virtual_resource* Texture2D::GetResource()
    {
        return m_texture.get();
    }
}
