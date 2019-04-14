#pragma once

#include "GraphicsPipelineStateDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct GraphicsPipelineStateDescription : GraphicsPipelineStateDescriptionT<GraphicsPipelineStateDescription>
    {
        GraphicsPipelineStateDescription() = default;

		Graphics::VertexShaderByteCode VS();
        void VS(Graphics::VertexShaderByteCode const& value);
		Graphics::PixelShaderByteCode PS();
        void PS(Graphics::PixelShaderByteCode const& value);
		Graphics::DomainShaderByteCode DS();
        void DS(Graphics::DomainShaderByteCode const& value);
		Graphics::HullShaderByteCode HS();
        void HS(Graphics::HullShaderByteCode const& value);
		Graphics::GeometryShaderByteCode GS();
        void GS(Graphics::GeometryShaderByteCode const& value);
		Graphics::StreamOutputDescription StreamOutput();
        void StreamOutput(Graphics::StreamOutputDescription const& value);
		Graphics::BlendDescription BlendState();
        void BlendState(Graphics::BlendDescription const& value);
        uint32_t SampleMask();
        void SampleMask(uint32_t value);
		Graphics::RasterizerDescription RasterizerState();
        void RasterizerState(Graphics::RasterizerDescription const& value);
		Graphics::DepthStencilDescription DepthStencilState();
        void DepthStencilState(Graphics::DepthStencilDescription const& value);
		Graphics::InputLayoutDescription InputLayout();
        void InputLayout(Graphics::InputLayoutDescription const& value);
		Graphics::IndexBufferStripCut IbStripCutValue();
        void IbStripCutValue(Graphics::IndexBufferStripCut const& value);
		Graphics::PrimitiveTopologyType PrimitiveTopology();
        void PrimitiveTopology(Graphics::PrimitiveTopologyType const& value);
        uint32_t NumRenderTargets();
        void NumRenderTargets(uint32_t value);

		IVector<GraphicsFormat> RtvFormats();
        void RtvFormats(IVector<GraphicsFormat> const& value);
        GraphicsFormat DsvFormat();
        void DsvFormat(GraphicsFormat const& value);
        SampleDescription Samples();
        void Samples(SampleDescription const& value);

		Graphics::VertexShaderByteCode		m_vertexShaderCode;
		Graphics::PixelShaderByteCode		m_pixelShaderCode;
		Graphics::DomainShaderByteCode		m_domainShaderCode;
		Graphics::HullShaderByteCode		m_hullShaderCode;
		Graphics::GeometryShaderByteCode	m_geometryShaderCode;

		Graphics::StreamOutputDescription	m_streamOutDescription;
		Graphics::BlendDescription			m_blendState;
		uint32_t							m_sampleMask;

		Graphics::RasterizerDescription		m_rasterizerState;
		Graphics::DepthStencilDescription	m_despthStencilState;

		Graphics::InputLayoutDescription	m_inputLayout;
		Graphics::IndexBufferStripCut		m_ibStripCut;
		Graphics::PrimitiveTopologyType		m_primitiveTopology;

    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct GraphicsPipelineStateDescription : GraphicsPipelineStateDescriptionT<GraphicsPipelineStateDescription, implementation::GraphicsPipelineStateDescription>
    {
    };
}
