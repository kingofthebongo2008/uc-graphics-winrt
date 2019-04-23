#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include "UniqueCreator.Graphics.Gpu.GraphicsPipelineState.g.h"

#include "shaders/default_graphics_signature.h"
#include "IGraphicsPipelineStateNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct GraphicsPipelineState : GraphicsPipelineStateT<GraphicsPipelineState, IGraphicsPipelineStateNative>
    {
		GraphicsPipelineState() = delete;
		GraphicsPipelineState(ResourceCreateContext const& ctx, GraphicsPipelineStateDescription const& d);

		uc::gx::dx12::graphics_pipeline_state*		GetPipelineState() override;

        private:

        Microsoft::WRL::ComPtr<ID3D12PipelineState> m_cached_pipeline_state;
        Microsoft::WRL::ComPtr<ID3D12RootSignature> m_cached_root_signature;
        uc::gx::dx12::root_signature_meta_data      m_cached_meta_data;
        uc::gx::dx12::graphics_pipeline_state       m_graphics_pipeline_state;
    };
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct GraphicsPipelineState : GraphicsPipelineStateT<GraphicsPipelineState, implementation::GraphicsPipelineState>
    {
    };
}
