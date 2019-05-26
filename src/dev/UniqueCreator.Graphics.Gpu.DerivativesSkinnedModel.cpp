#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModel.h"

#define UWP
#include <uc/gx/lip/lip.h>
#include <uc/gx/lip_utils.h>
#include "file.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace uc;

    DerivativesSkinnedModel::DerivativesSkinnedModel(UniqueCreator::Graphics::Gpu::ResourceCreateContext const& rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload)
    {
        //auto mesh = lip::create_from_compressed_lip_file<lip::derivatives_skinned_model>(L"appdata/models/military_mechanic.derivatives_skinned_model.model");
        auto mesh = lip::create_from_compressed_lip_file<lip::derivatives_skinned_model>(payload.c_str());
        throw hresult_not_implemented();
    }
    UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance DerivativesSkinnedModel::MakeInstance(UniqueCreator::Graphics::Gpu::Matrix44 const& d)
    {
        throw hresult_not_implemented();
    }
    void DerivativesSkinnedModel::BeginDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        throw hresult_not_implemented();
    }
    void DerivativesSkinnedModel::EndDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        throw hresult_not_implemented();
    }
    void DerivativesSkinnedModel::BeginAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        throw hresult_not_implemented();
    }
    void DerivativesSkinnedModel::EndAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        throw hresult_not_implemented();
    }
}

