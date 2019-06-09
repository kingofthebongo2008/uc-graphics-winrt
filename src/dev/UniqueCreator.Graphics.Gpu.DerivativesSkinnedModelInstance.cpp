#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModelInstance.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    DerivativesSkinnedModelInstance::DerivativesSkinnedModelInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModel const& Model, UniqueCreator::Graphics::Gpu::Matrix44 const& instance) :
    m_model(Model)
    {
        m_transform.r[0] = math::set(instance.r00, instance.r01, instance.r02, instance.r02);
        m_transform.r[1] = math::set(instance.r10, instance.r11, instance.r12, instance.r12);
        m_transform.r[2] = math::set(instance.r20, instance.r21, instance.r22, instance.r22);
        m_transform.r[3] = math::set(instance.r30, instance.r31, instance.r32, instance.r32);
    }

    void DerivativesSkinnedModelInstance::SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
    
    }

    void DerivativesSkinnedModelInstance::SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
    
    }
}
