#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModelInstance.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct DerivativesSkinnedModelInstance : DerivativesSkinnedModelInstanceT<DerivativesSkinnedModelInstance>
    {
        DerivativesSkinnedModelInstance() = default;

        DerivativesSkinnedModelInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModel const& Model, UniqueCreator::Graphics::Gpu::Matrix44 const& instance);
        void SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedModelInstance : DerivativesSkinnedModelInstanceT<DerivativesSkinnedModelInstance, implementation::DerivativesSkinnedModelInstance>
    {
    };
}
