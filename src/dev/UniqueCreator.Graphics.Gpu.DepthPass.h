#pragma once
#include "UniqueCreator.Graphics.Gpu.DepthPass.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct DepthPass : DepthPassT<DepthPass>
    {
        DepthPass() = default;

        void AddInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance const& instance);
        void Submit(UniqueCreator::Graphics::Gpu::DepthPassData const& passData, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx);

        private:
        std::vector< UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance> m_instances;
    };
}
