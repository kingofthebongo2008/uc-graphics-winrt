#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModelInstance.h"

#include "IGraphicsComputeCommandContextNative.h"
#include <uc/gx/dx12/dx12.h>
#include <shaders/interop.h>


namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    DerivativesSkinnedModelInstance::DerivativesSkinnedModelInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModel const& Model, UniqueCreator::Graphics::Gpu::Matrix44 const& instance) :
    m_model(Model)
    {
        m_world.r[0] = math::set(instance.r00, instance.r01, instance.r02, instance.r03);
        m_world.r[1] = math::set(instance.r10, instance.r11, instance.r12, instance.r13);
        m_world.r[2] = math::set(instance.r20, instance.r21, instance.r22, instance.r23);
        m_world.r[3] = math::set(instance.r30, instance.r31, instance.r32, instance.r33);
        m_mesh       = Model.as<IDerivativesSkinnedModelNative>()->GetMesh();
    }

    void DerivativesSkinnedModelInstance::SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics   = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        {
            auto m = transpose(m_world);
            graphics->set_graphics_root_constants(0, sizeof(m) / sizeof(uint32_t), &m, offsetof(interop::draw_call, m_world) / sizeof(uint32_t));
        }

        graphics->draw_indexed(m_mesh->m_mesh.m_indices_size / 4);
    }

    void DerivativesSkinnedModelInstance::SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        {
            auto m = transpose(m_world);
            graphics->set_graphics_root_constants(0, sizeof(m) / sizeof(uint32_t), &m, offsetof(interop::draw_call, m_world) / sizeof(uint32_t));
        }

        for (auto i = 0U; i < m_mesh->m_mesh_opaque.m_opaque_textures.size(); ++i)
        {
            graphics->set_graphics_dynamic_descriptor(4, m_mesh->m_mesh_opaque.m_opaque_textures[i]->srv());
            graphics->draw_indexed(m_mesh->m_mesh_opaque.m_opaque_ranges[i].index_count(), m_mesh->m_mesh_opaque.m_opaque_ranges[i].m_begin);
        }

    }
}
