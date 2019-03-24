﻿#pragma once

#include "ComputePipelineStateDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ComputePipelineStateDescription : ComputePipelineStateDescriptionT<ComputePipelineStateDescription>
    {
        ComputePipelineStateDescription() = default;

        UniqueCreator::Graphics::ComputeShaderByteCode CS();
        void CS(UniqueCreator::Graphics::ComputeShaderByteCode const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ComputePipelineStateDescription : ComputePipelineStateDescriptionT<ComputePipelineStateDescription, implementation::ComputePipelineStateDescription>
    {
    };
}