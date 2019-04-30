#include "pch.h"
#include "ByteAddressBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    ByteAddressBuffer::ByteAddressBuffer(managed_byteaddress_gpu_buffer b) : m_buffer(std::move(b))
    {

    }

    uc::gx::dx12::gpu_virtual_resource* ByteAddressBuffer::GetResource()
    {
        return m_buffer.get();
    }

    GpuVirtualAddress ByteAddressBuffer::VirtualAddress()
    {
        return { m_buffer->virtual_address() };
    }

    CpuDescriptorHandle ByteAddressBuffer::SRV() const
    {
        D3D12_CPU_DESCRIPTOR_HANDLE h = m_buffer->srv();
        return { h.ptr };
    }

    CpuDescriptorHandle ByteAddressBuffer::UAV() const
    {
        D3D12_CPU_DESCRIPTOR_HANDLE h = m_buffer->uav();
        return { h.ptr };
    }

    void ByteAddressBuffer::Dummy1()
    {
        throw hresult_not_implemented();
    }
}
