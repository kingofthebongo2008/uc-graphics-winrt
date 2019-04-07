#pragma once
#include <windows.foundation.h>
#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            struct compute_pipeline_state;
        }
    }
}

namespace winrt::UniqueCreator::Graphics
{
    struct __declspec(uuid("06ECDF53-E89E-478D-93D9-AC9CC1B5D503")) __declspec(novtable) IComputePipelineStateNative : ::IUnknown
    {
        virtual uc::gx::dx12::compute_pipeline_state* GetPipelineState() = 0;
    };
}
