#pragma once

#include "UniqueCreator.Graphics.Gpu.ComputePipelineStateDescription.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct ComputePipelineStateDescription : ComputePipelineStateDescriptionT<ComputePipelineStateDescription>
    {
        ComputePipelineStateDescription() = default;

        ComputeShaderByteCode CS();
        void CS(ComputeShaderByteCode const& value);

		ComputeShaderByteCode m_code;
    };
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct ComputePipelineStateDescription : ComputePipelineStateDescriptionT<ComputePipelineStateDescription, implementation::ComputePipelineStateDescription>
    {
    };
}
