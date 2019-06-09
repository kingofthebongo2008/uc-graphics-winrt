#pragma once
#include "UniqueCreator.Graphics.Gpu.AlbedoPass.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct AlbedoPass : AlbedoPassT<AlbedoPass>
    {
        AlbedoPass() = default;

        void AddInstance(UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance const& instance);
        void Submit(UniqueCreator::Graphics::Gpu::AlbedoPassData const& passData, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx);

        private:

        std::vector< UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance> m_instances;
    };
}
