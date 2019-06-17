#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.DepthPass.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    void DepthPass::AddInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance const& instance)
    {
        m_instances.push_back(instance);
    }

    void DepthPass::Submit(UniqueCreator::Graphics::Gpu::DepthPassData const& passData, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx)
    {

    }
}
