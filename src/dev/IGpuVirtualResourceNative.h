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
    struct __declspec(uuid("A8C50540-847B-460C-8E1C-55D3E5E451EF")) __declspec(novtable) IGpuVirtualResourceNative : ::IUnknown
    {
        virtual uc::gx::dx12::gpu_fence* GetFenceHandle() = 0;
    };
}
