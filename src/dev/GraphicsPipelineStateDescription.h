#pragma once

#include "GraphicsPipelineStateDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct GraphicsPipelineStateDescription : GraphicsPipelineStateDescriptionT<GraphicsPipelineStateDescription>
    {
        GraphicsPipelineStateDescription() = default;

        UniqueCreator::Graphics::VertexShaderByteCode VS();
        void VS(UniqueCreator::Graphics::VertexShaderByteCode const& value);
        UniqueCreator::Graphics::PixelShaderByteCode PS();
        void PS(UniqueCreator::Graphics::PixelShaderByteCode const& value);
        UniqueCreator::Graphics::DomainShaderByteCode DS();
        void DS(UniqueCreator::Graphics::DomainShaderByteCode const& value);
        UniqueCreator::Graphics::HullShaderByteCode HS();
        void HS(UniqueCreator::Graphics::HullShaderByteCode const& value);
        UniqueCreator::Graphics::GeometryShaderByteCode GS();
        void GS(UniqueCreator::Graphics::GeometryShaderByteCode const& value);
        UniqueCreator::Graphics::StreamOutputDescription StreamOutput();
        void StreamOutput(UniqueCreator::Graphics::StreamOutputDescription const& value);
        UniqueCreator::Graphics::BlendDescription BlendState();
        void BlendState(UniqueCreator::Graphics::BlendDescription const& value);
        uint32_t SampleMask();
        void SampleMask(uint32_t value);
        UniqueCreator::Graphics::RasterizerDescription RasterizerState();
        void RasterizerState(UniqueCreator::Graphics::RasterizerDescription const& value);
        UniqueCreator::Graphics::DepthStencilDescription DepthStencilState();
        void DepthStencilState(UniqueCreator::Graphics::DepthStencilDescription const& value);
        UniqueCreator::Graphics::InputLayoutDescription InputLayout();
        void InputLayout(UniqueCreator::Graphics::InputLayoutDescription const& value);
        UniqueCreator::Graphics::IndexBufferStripCut IbStripCutValue();
        void IbStripCutValue(UniqueCreator::Graphics::IndexBufferStripCut const& value);
        UniqueCreator::Graphics::PrimitiveTopologyType PrimitiveTopologyType();
        void PrimitiveTopologyType(UniqueCreator::Graphics::PrimitiveTopologyType const& value);
        uint32_t NumRenderTargets();
        void NumRenderTargets(uint32_t value);
        Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::GraphicsFormat> RtvFormats();
        void RtvFormats(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::GraphicsFormat> const& value);
        UniqueCreator::Graphics::GraphicsFormat DsvFormat();
        void DsvFormat(UniqueCreator::Graphics::GraphicsFormat const& value);
        UniqueCreator::Graphics::SampleDescription SampleDescription();
        void SampleDescription(UniqueCreator::Graphics::SampleDescription const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct GraphicsPipelineStateDescription : GraphicsPipelineStateDescriptionT<GraphicsPipelineStateDescription, implementation::GraphicsPipelineStateDescription>
    {
    };
}
