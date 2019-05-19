#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModel.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct DerivativesSkinnedModel : DerivativesSkinnedModelT<DerivativesSkinnedModel>
    {
        DerivativesSkinnedModel() = default;

        DerivativesSkinnedModel(UniqueCreator::Graphics::Gpu::ResourceCreateContext const& rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload);
        UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance MakeInstance(UniqueCreator::Graphics::Gpu::Matrix44 const& d);
        void BeginDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void EndDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void BeginAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void EndAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedModel : DerivativesSkinnedModelT<DerivativesSkinnedModel, implementation::DerivativesSkinnedModel>
    {
    };
}
