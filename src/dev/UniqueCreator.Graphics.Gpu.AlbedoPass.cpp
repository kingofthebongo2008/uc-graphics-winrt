#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.AlbedoPass.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    void AlbedoPass::AddInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance const& instance)
    {
        m_instances.push_back(instance);
    }

    void AlbedoPass::Submit(UniqueCreator::Graphics::Gpu::AlbedoPassData const& passData, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx)
    {
        
    }
}
