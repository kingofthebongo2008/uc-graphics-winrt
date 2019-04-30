#include "pch.h"
#include "UploadBuffer.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    UploadBuffer::UploadBuffer(managed_gpu_upload_buffer b) : m_buffer(std::move(b))
    {

    }

    uc::gx::dx12::gpu_virtual_resource* UploadBuffer::GetResource()
    {
        return m_buffer.get();
    }

    GpuVirtualAddress UploadBuffer::VirtualAddress()
    {
        return { m_buffer->virtual_address() };
    }

    void UploadBuffer::Dummy1()
    {
        throw hresult_not_implemented();
    }
}
