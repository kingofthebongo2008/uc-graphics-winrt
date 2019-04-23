#include "pch.h"

#include "UniqueCreator.Graphics.Gpu.GraphicsPipelineStateDescription.h"
#include <Windows.Foundation.Collections.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	GraphicsPipelineStateDescription::GraphicsPipelineStateDescription()
	{
		m_rtvFormats  = single_threaded_vector(std::vector<GraphicsFormat>());
	}

	Gpu::VertexShaderByteCode GraphicsPipelineStateDescription::VS()
    {
		return m_vertexShaderCode;
    }

    void GraphicsPipelineStateDescription::VS(Gpu::VertexShaderByteCode const& value)
    {
		m_vertexShaderCode = value;
    }

	Gpu::PixelShaderByteCode GraphicsPipelineStateDescription::PS()
    {
		return m_pixelShaderCode;
    }

    void GraphicsPipelineStateDescription::PS(Gpu::PixelShaderByteCode const& value)
    {
		m_pixelShaderCode = value;
    }

	Gpu::DomainShaderByteCode GraphicsPipelineStateDescription::DS()
    {
		return m_domainShaderCode;
    }

    void GraphicsPipelineStateDescription::DS(Gpu::DomainShaderByteCode const& value)
    {
		m_domainShaderCode = value;
    }

	Gpu::HullShaderByteCode GraphicsPipelineStateDescription::HS()
    {
		return m_hullShaderCode;
    }

    void GraphicsPipelineStateDescription::HS(Gpu::HullShaderByteCode const& value)
    {
		m_hullShaderCode = value;
    }

	Gpu::GeometryShaderByteCode GraphicsPipelineStateDescription::GS()
    {
		return m_geometryShaderCode;
    }

    void GraphicsPipelineStateDescription::GS(Gpu::GeometryShaderByteCode const& value)
    {
		m_geometryShaderCode = value;
    }

	Gpu::StreamOutputDescription GraphicsPipelineStateDescription::StreamOutput()
    {
		return m_streamOutDescription;
    }

    void GraphicsPipelineStateDescription::StreamOutput(Gpu::StreamOutputDescription const& value)
    {
		m_streamOutDescription = value;
    }

	Gpu::BlendDescription GraphicsPipelineStateDescription::BlendState()
    {
		return m_blendState;
    }

    void GraphicsPipelineStateDescription::BlendState(Gpu::BlendDescription const& value)
    {
		m_blendState = value;
    }

    uint32_t GraphicsPipelineStateDescription::SampleMask()
    {
		return m_sampleMask;
    }

    void GraphicsPipelineStateDescription::SampleMask(uint32_t value)
    {
		m_sampleMask = value;
    }

	RasterizerDescription GraphicsPipelineStateDescription::RasterizerState()
    {
		return m_rasterizerState;
    }

    void GraphicsPipelineStateDescription::RasterizerState(RasterizerDescription const& value)
    {
		m_rasterizerState = value;
    }

	DepthStencilDescription GraphicsPipelineStateDescription::DepthStencilState()
    {
        return m_despthStencilState;
    }

    void GraphicsPipelineStateDescription::DepthStencilState(DepthStencilDescription const& value)
    {
		m_despthStencilState = value;
    }

	Gpu::InputLayoutDescription GraphicsPipelineStateDescription::InputLayout()
    {
		return m_inputLayout;
    }

    void GraphicsPipelineStateDescription::InputLayout(Gpu::InputLayoutDescription const& value)
    {
		m_inputLayout = value;
    }

	IndexBufferStripCut GraphicsPipelineStateDescription::IbStripCutValue()
    {
		return m_ibStripCut;
    }

    void GraphicsPipelineStateDescription::IbStripCutValue(IndexBufferStripCut const& value)
    {
		m_ibStripCut = value;
    }

	PrimitiveTopologyType GraphicsPipelineStateDescription::PrimitiveTopology()
    {
		return m_primitiveTopology;
    }

    void GraphicsPipelineStateDescription::PrimitiveTopology(PrimitiveTopologyType const& value)
    {
		m_primitiveTopology = value;
    }

    IVector<GraphicsFormat> GraphicsPipelineStateDescription::RtvFormats()
    {
		return m_rtvFormats;
    }

    void GraphicsPipelineStateDescription::RtvFormats(IVector<GraphicsFormat> const& value)
    {
		m_rtvFormats = value;
    }

	GraphicsFormat GraphicsPipelineStateDescription::DsvFormat()
    {
		return m_dsvFormat;
    }

    void GraphicsPipelineStateDescription::DsvFormat(GraphicsFormat const& value)
    {
		m_dsvFormat = value;
    }

	SampleDescription GraphicsPipelineStateDescription::Samples()
    {
        return m_samples;
    }

    void GraphicsPipelineStateDescription::Samples(SampleDescription const& value)
    {
		m_samples = value;
    }
}
