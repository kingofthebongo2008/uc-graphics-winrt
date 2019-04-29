#pragma once
#include "UniqueCreator.Graphics.Gpu.Buffer.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct Buffer : BufferT<Buffer>
    {
        Buffer() = default;

        UniqueCreator::Graphics::Gpu::GpuVirtualAddress VirtualAddress();
        UniqueCreator::Graphics::Gpu::CpuDescriptorHandle SRV();
        UniqueCreator::Graphics::Gpu::CpuDescriptorHandle UAV();
        void Dummy1();
    };
}
