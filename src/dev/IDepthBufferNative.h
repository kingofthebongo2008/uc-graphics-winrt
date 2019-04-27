#pragma once

#include <windows.foundation.h>
#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            class gpu_depth_buffer;
            class gpu_depth_stencil_buffer;
        }
    }
}

namespace winrt::UniqueCreator::Graphics
{
    struct __declspec(uuid("47604267-A83F-472F-813A-ED1DF5D56100")) __declspec(novtable) IDepthBufferNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_depth_buffer* GetDepthBuffer() = 0;
    };
}

namespace winrt::UniqueCreator::Graphics
{

    struct __declspec(uuid("9F2BAA95-61C9-499B-906A-2762EC8C5F73")) __declspec(novtable) IDepthStencilBufferNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_depth_stencil_buffer* GetDepthStencilBuffer() = 0;
    };
}
