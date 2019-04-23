#pragma once

#include "UniqueCreator.Graphics.Gpu.GraphicsPipelineStateDescription.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace Windows::Foundation::Collections;

    struct GraphicsPipelineStateDescription : GraphicsPipelineStateDescriptionT<GraphicsPipelineStateDescription>
    {
		GraphicsPipelineStateDescription();

		Gpu::VertexShaderByteCode VS();
        void VS(Gpu::VertexShaderByteCode const& value);
		Gpu::PixelShaderByteCode PS();
        void PS(Gpu::PixelShaderByteCode const& value);
		Gpu::DomainShaderByteCode DS();
        void DS(Gpu::DomainShaderByteCode const& value);
		Gpu::HullShaderByteCode HS();
        void HS(Gpu::HullShaderByteCode const& value);
		Gpu::GeometryShaderByteCode GS();
        void GS(Gpu::GeometryShaderByteCode const& value);
		Gpu::StreamOutputDescription StreamOutput();
        void StreamOutput(Gpu::StreamOutputDescription const& value);
		Gpu::BlendDescription BlendState();
        void BlendState(Gpu::BlendDescription const& value);
        uint32_t SampleMask();
        void SampleMask(uint32_t value);
		RasterizerDescription RasterizerState();
        void RasterizerState(RasterizerDescription const& value);
		DepthStencilDescription DepthStencilState();
        void DepthStencilState(DepthStencilDescription const& value);
		Gpu::InputLayoutDescription InputLayout();
        void InputLayout(Gpu::InputLayoutDescription const& value);
		IndexBufferStripCut IbStripCutValue();
        void IbStripCutValue(IndexBufferStripCut const& value);
		PrimitiveTopologyType PrimitiveTopology();
        void PrimitiveTopology(PrimitiveTopologyType const& value);
        

		IVector<GraphicsFormat> RtvFormats();
        void RtvFormats(IVector<GraphicsFormat> const& value);
        GraphicsFormat DsvFormat();
        void DsvFormat(GraphicsFormat const& value);
        SampleDescription Samples();
        void Samples(SampleDescription const& value);

		VertexShaderByteCode		m_vertexShaderCode;
		PixelShaderByteCode			m_pixelShaderCode;
		DomainShaderByteCode		m_domainShaderCode;
		HullShaderByteCode			m_hullShaderCode;
		GeometryShaderByteCode		m_geometryShaderCode;

		StreamOutputDescription		m_streamOutDescription;
		BlendDescription			m_blendState;
		uint32_t					m_sampleMask;

		RasterizerDescription		m_rasterizerState;
		DepthStencilDescription		m_despthStencilState;

		InputLayoutDescription		m_inputLayout;
		IndexBufferStripCut			m_ibStripCut;
		PrimitiveTopologyType		m_primitiveTopology;

		SampleDescription			m_samples;

		IVector<GraphicsFormat>		m_rtvFormats;
		GraphicsFormat				m_dsvFormat;
    };
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct GraphicsPipelineStateDescription : GraphicsPipelineStateDescriptionT<GraphicsPipelineStateDescription, implementation::GraphicsPipelineStateDescription>
    {
    };
}
