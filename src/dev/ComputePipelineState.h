#pragma once

#include "ComputePipelineState.g.h"

#include "shaders/default_compute_signature.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ComputePipelineState : ComputePipelineStateT<ComputePipelineState>
    {
        ComputePipelineState() = delete;
        ComputePipelineState(UniqueCreator::Graphics::ResourceCreateContext const& ctx, UniqueCreator::Graphics::ComputePipelineStateDescription const& d);

        void GetCachedBlob();

        private:

        Microsoft::WRL::ComPtr<ID3D12PipelineState> m_cached_pipeline_state;
        Microsoft::WRL::ComPtr<ID3D12RootSignature> m_cached_root_signature;
        uc::gx::dx12::root_signature_meta_data      m_cached_meta_data;
        uc::gx::dx12::compute_pipeline_state        m_compute_pipeline_state;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ComputePipelineState : ComputePipelineStateT<ComputePipelineState, implementation::ComputePipelineState>
    {
    };
}
