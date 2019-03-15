#pragma once
#include <windows.foundation.h>
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
    struct __declspec(uuid("25866D8D-2099-4B86-8655-27D5B0022457")) __declspec(novtable) IFenceHandleNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_fence* GetFenceHandle() = 0;
    };
}
