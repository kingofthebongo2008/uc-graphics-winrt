#pragma once

#include "winrt/UniqueCreator.Graphics.h"

#include "IBackBufferNative.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct BackBuffer : implements<BackBuffer, IBackBuffer, IPixelBuffer, IGpuVirtualResource, IGpuVirtualResourceNative, IBackBufferNative >
    {
        BackBuffer() = default;

        void Dummy1() {}

        GpuVirtualAddress VirtualAddress() const;

        uc::gx::dx12::gpu_back_buffer* GetBackBuffer() override;
        uc::gx::dx12::gpu_virtual_resource* GetResource() override;

        Size2D            Size2D() const;
        Size3D            Size3D() const;
        private:
   };  
}

