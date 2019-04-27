#pragma once
#include <windows.foundation.h>

#include "IPixelBufferNative.h"

#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            class gpu_back_buffer;
            class gpu_color_buffer;
        }
    }
}

namespace winrt::UniqueCreator::Graphics
{
    struct __declspec(uuid("15DB129D-822D-4EBB-AC1C-1A2297D86705")) __declspec(novtable) IBackBufferNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_back_buffer* GetBackBuffer() = 0;
    };
}

namespace winrt::UniqueCreator::Graphics
{

    struct __declspec(uuid("BC8E34D3-FF72-46B9-8973-C2F0399922AB")) __declspec(novtable) IColorBufferNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_color_buffer* GetColorBuffer() = 0;
    };
}
