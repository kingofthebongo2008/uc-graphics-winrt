#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModelInstance.g.h"

#include <uc/math/math.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc;

    struct DerivativesSkinnedModelInstance : DerivativesSkinnedModelInstanceT<DerivativesSkinnedModelInstance>
    {
        DerivativesSkinnedModelInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModel const& Model, UniqueCreator::Graphics::Gpu::Matrix44 const& instance);

        void SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);

        private:
        const UniqueCreator::Graphics::Gpu::DerivativesSkinnedModel m_model;
        math::float4x4                                              m_transform;
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedModelInstance : DerivativesSkinnedModelInstanceT<DerivativesSkinnedModelInstance, implementation::DerivativesSkinnedModelInstance>
    {
    };
}
