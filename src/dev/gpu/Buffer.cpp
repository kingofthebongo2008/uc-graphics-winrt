#include "pch.h"
#include "Buffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    UniqueCreator::Graphics::Gpu::GpuVirtualAddress Buffer::VirtualAddress()
    {
		return GpuVirtualAddress();
    }
    UniqueCreator::Graphics::Gpu::CpuDescriptorHandle Buffer::SRV()
    {
		return CpuDescriptorHandle();
    }
    UniqueCreator::Graphics::Gpu::CpuDescriptorHandle Buffer::UAV()
    {
		return CpuDescriptorHandle();
    }

	void Buffer::Dummy1()
    {
        throw hresult_not_implemented();
    }
}
