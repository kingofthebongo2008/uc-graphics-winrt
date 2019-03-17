#pragma once

#include "winrt/UniqueCreator.Graphics.h"

#include "IBackBufferNative.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    using namespace uc::gx::dx12;

    struct BackBuffer : implements<BackBuffer, IBackBuffer, IPixelBuffer, IGpuVirtualResource, IGpuVirtualResourceNative, IBackBufferNative >
    {
        BackBuffer(gpu_back_buffer* b);

        void Dummy1() {}

        GpuVirtualAddress VirtualAddress() const;

        gpu_back_buffer*        GetBackBuffer() override;
        gpu_virtual_resource*   GetResource() override;

        Size2D            Size2D() const;
        Size3D            Size3D() const;
        private:
        gpu_back_buffer*  m_back_buffer;
   };  
}

