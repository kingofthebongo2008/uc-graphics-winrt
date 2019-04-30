#pragma once

#include "UniqueCreator.Graphics.Gpu.ByteAddressBuffer.g.h"
#include "IGpuVirtualResourceNative.h"
#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc::gx::dx12;

    struct ByteAddressBuffer : ByteAddressBufferT<ByteAddressBuffer, IGpuVirtualResourceNative >
    {
        ByteAddressBuffer(managed_byteaddress_gpu_buffer b);

        GpuVirtualAddress   VirtualAddress();
        CpuDescriptorHandle SRV() const;
        CpuDescriptorHandle UAV() const;

        gpu_virtual_resource* GetResource();

        void Dummy1();

        managed_byteaddress_gpu_buffer m_buffer;
    };
}
