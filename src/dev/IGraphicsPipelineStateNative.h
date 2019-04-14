#pragma once
#include <windows.foundation.h>
#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            struct graphics_pipeline_state;
        }
    }
}

namespace winrt::UniqueCreator::Graphics
{
    struct __declspec(uuid("BAABC13E-9291-439E-9C12-EF441FCC9A49")) __declspec(novtable) IGraphicsPipelineStateNative : ::IUnknown
    {
        virtual uc::gx::dx12::graphics_pipeline_state* GetPipelineState() = 0;
    };
}
