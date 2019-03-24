#pragma once

#include "ComputePipelineState.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ComputePipelineState : ComputePipelineStateT<ComputePipelineState>
    {
        ComputePipelineState() = delete;
        ComputePipelineState(UniqueCreator::Graphics::ResourceCreateContext const& ctx, UniqueCreator::Graphics::ComputePipelineStateDescription const& d);

        void GetCachedBlob();
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ComputePipelineState : ComputePipelineStateT<ComputePipelineState, implementation::ComputePipelineState>
    {
    };
}
