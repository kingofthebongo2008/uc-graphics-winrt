#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedMaterial.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct DerivativesSkinnedMaterial : DerivativesSkinnedMaterialT<DerivativesSkinnedMaterial>
    {
        DerivativesSkinnedMaterial() = default;

        DerivativesSkinnedMaterial(UniqueCreator::Graphics::Gpu::ResourceCreateContext const& rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload);
        void SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedMaterial : DerivativesSkinnedMaterialT<DerivativesSkinnedMaterial, implementation::DerivativesSkinnedMaterial>
    {
    };
}
