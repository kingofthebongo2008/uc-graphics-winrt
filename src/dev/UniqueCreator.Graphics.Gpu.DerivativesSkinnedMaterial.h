#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedMaterial.g.h"

#include <uc/gx/dx12/dx12.h>
#include <derivatives_skinned_model_albedo.h>
#include <derivatives_skinned_model_depth.h>


namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc;
    struct DerivativesSkinnedMaterial : DerivativesSkinnedMaterialT<DerivativesSkinnedMaterial>
    {
        DerivativesSkinnedMaterial(UniqueCreator::Graphics::Gpu::ResourceCreateContext const& rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload);

        void SubmitDepth(UniqueCreator::Graphics::Gpu::DepthPassData const& p, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void SubmitAlbedo(UniqueCreator::Graphics::Gpu::AlbedoPassData const& p, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);

        private:

        gx::dx12::derivatives_skinned_model_albedo::graphics_pipeline_state* m_albedo_pso = nullptr;
        gx::dx12::derivatives_skinned_model_depth::graphics_pipeline_state*  m_depth_pso = nullptr;
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedMaterial : DerivativesSkinnedMaterialT<DerivativesSkinnedMaterial, implementation::DerivativesSkinnedMaterial>
    {
    };
}
