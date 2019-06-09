#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedMaterial.g.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModel.g.h"


#include "IDerivativesSkinnedModelNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc;

    struct DerivativesSkinnedModel : DerivativesSkinnedModelT<DerivativesSkinnedModel, IDerivativesSkinnedModelNative>
    {
        DerivativesSkinnedModel(UniqueCreator::Graphics::Gpu::DerivativesSkinnedMaterial const& m, UniqueCreator::Graphics::Gpu::ResourceCreateContext const& rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload);

        void SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);

        derivatives_skinned_mesh* GetMesh();

        private:
        UniqueCreator::Graphics::Gpu::DerivativesSkinnedMaterial m_material;
        derivatives_skinned_mesh                                 m_mesh;
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedModel : DerivativesSkinnedModelT<DerivativesSkinnedModel, implementation::DerivativesSkinnedModel>
    {

    };
}
