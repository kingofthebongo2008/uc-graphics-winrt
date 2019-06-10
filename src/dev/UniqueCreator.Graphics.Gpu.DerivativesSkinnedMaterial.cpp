#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedMaterial.h"

#include "IResourceCreateContextNative.h"
#include "IGraphicsComputeCommandContextNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    DerivativesSkinnedMaterial::DerivativesSkinnedMaterial(UniqueCreator::Graphics::Gpu::ResourceCreateContext const& _rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload)
    {
        auto d          = _rc.as<IResourceCreateContextNative>()->GetDevice();
        auto rc         = _rc.as<IResourceCreateContextNative>()->GetResourceCreateContext();

        m_albedo_pso    = gx::dx12::derivatives_skinned_model_albedo::create_pso(d, rc->null_cbv(), rc->null_srv(), rc->null_uav(), rc->null_sampler());
        m_depth_pso     = gx::dx12::derivatives_skinned_model_depth::create_pso(d, rc->null_cbv(), rc->null_srv(), rc->null_uav(), rc->null_sampler());
    }

    void DerivativesSkinnedMaterial::SubmitDepth(UniqueCreator::Graphics::Gpu::DepthPassData const& p, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        graphics->set_pso(m_depth_pso);
        //graphics->set_graphics_constant_buffer(1, f);
    }

    void DerivativesSkinnedMaterial::SubmitAlbedo(UniqueCreator::Graphics::Gpu::AlbedoPassData const& p, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        graphics->set_pso(m_albedo_pso);
        //graphics->set_graphics_constant_buffer(1, f);
    }
}
