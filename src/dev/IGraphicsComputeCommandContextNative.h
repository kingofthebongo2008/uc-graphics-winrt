#pragma once
#include <windows.foundation.h>
#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            struct gpu_graphics_compute_command_context;
        }
    }
}

namespace winrt::UniqueCreator::Graphics::Gpu
{
    struct __declspec(uuid("D3000798-0279-4E2B-81B2-B6B4B79D3E05")) __declspec(novtable) IGraphicsComputeCommandContextNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_graphics_compute_command_context* GetContext() = 0;
    };
}
