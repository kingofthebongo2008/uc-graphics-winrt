#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedMaterial.h"

#include "IResourceCreateContextNative.h"
#include "IGraphicsComputeCommandContextNative.h"

#include <shaders/interop.h>


namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    math::float4x4 toMatrix(UniqueCreator::Graphics::Gpu::Matrix44 const& instance)
    {
        math::float4x4 result;

        result.r[0] = math::set(instance.r00, instance.r01, instance.r02, instance.r02);
        result.r[1] = math::set(instance.r10, instance.r11, instance.r12, instance.r12);
        result.r[2] = math::set(instance.r20, instance.r21, instance.r22, instance.r22);
        result.r[3] = math::set(instance.r30, instance.r31, instance.r32, instance.r32);
        return result;
    }

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

        math::float4x4 perspective  = toMatrix(p.Camera.PerspectiveTransform);
        math::float4x4 view         = toMatrix(p.Camera.ViewTransform);

        interop::frame f;
        f.m_perspective.m_value = transpose(perspective);
        f.m_view.m_value = transpose(view);

        graphics->set_graphics_constant_buffer(1, f);
    }

    void DerivativesSkinnedMaterial::SubmitAlbedo(UniqueCreator::Graphics::Gpu::AlbedoPassData const& p, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        graphics->set_pso(m_albedo_pso);

        math::float4x4 perspective = toMatrix(p.Camera.PerspectiveTransform);
        math::float4x4 view = toMatrix(p.Camera.ViewTransform);

        interop::frame f;
        f.m_perspective.m_value = transpose(perspective);
        f.m_view.m_value = transpose(view);

        graphics->set_graphics_constant_buffer(1, f);
    }
}
