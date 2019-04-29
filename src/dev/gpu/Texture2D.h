#pragma once
#include "UniqueCreator.Graphics.Gpu.Texture2D.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct Texture2D : Texture2DT<Texture2D>
    {
        Texture2D() = default;

        UniqueCreator::Graphics::Gpu::GpuVirtualAddress VirtualAddress();
        UniqueCreator::Graphics::Gpu::Size2D Size2D();
        UniqueCreator::Graphics::Gpu::Size3D Size3D();
        UniqueCreator::Graphics::Gpu::CpuDescriptorHandle SRV();
        UniqueCreator::Graphics::Gpu::CpuDescriptorHandle UAV();
        void Dummy1();
    };
}
