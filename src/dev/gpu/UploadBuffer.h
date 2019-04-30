#pragma once

#include "UniqueCreator.Graphics.Gpu.UploadBuffer.g.h"
#include "IGpuVirtualResourceNative.h"
#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc::gx::dx12;

    struct UploadBuffer : UploadBufferT<UploadBuffer, IGpuVirtualResourceNative >
    {
        UploadBuffer(managed_gpu_upload_buffer b);

        GpuVirtualAddress   VirtualAddress();
        gpu_virtual_resource* GetResource();

        void Dummy1();
        managed_gpu_upload_buffer m_buffer;
    };
}
