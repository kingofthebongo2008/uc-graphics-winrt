#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include "UniqueCreator.Graphics.Gpu.SwapChainBuffer.g.h"
#include "IBackBufferNative.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc::gx::dx12;

    struct BackBuffer : SwapChainBufferT<BackBuffer, IGpuVirtualResourceNative, IBackBufferNative >
    {
        BackBuffer(gpu_back_buffer* b);

        void Dummy1() {}

        GpuVirtualAddress VirtualAddress() const;

        gpu_back_buffer*        GetBackBuffer();
        gpu_virtual_resource*   GetResource();

        Size2D            Size2D() const;
        Size3D            Size3D() const;
        private:
        gpu_back_buffer*  m_back_buffer;
   };  
}

