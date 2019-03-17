#pragma once
#include <windows.foundation.h>

#include "IGpuVirtualResourceNative.h"

#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            struct gpu_fence;
        }
    }
}

namespace winrt::UniqueCreator::Graphics
{
    struct __declspec(uuid("407041BB-F116-464D-B0BC-9DA73E8A894D")) __declspec(novtable) IPixelBufferNative : IGpuVirtualResourceNative
    {
        virtual uc::gx::dx12::gpu_fence* GetFenceHandle() = 0;
    };
}
