#include "pch.h"
#include "GraphicsPipelineStateDescription.h"

#include <Windows.Foundation.Collections.h>

namespace winrt::UniqueCreator::Graphics::implementation
{

	GeometryShaderByteCode   m_geometryShaderShaderCode;

	Graphics::VertexShaderByteCode GraphicsPipelineStateDescription::VS()
    {
		return m_vertexShaderCode;
    }

    void GraphicsPipelineStateDescription::VS(Graphics::VertexShaderByteCode const& value)
    {
		m_vertexShaderCode = value;
    }

	Graphics::PixelShaderByteCode GraphicsPipelineStateDescription::PS()
    {
		throw m_pixelShaderCode;
    }

    void GraphicsPipelineStateDescription::PS(Graphics::PixelShaderByteCode const& value)
    {
		m_pixelShaderCode = value;
    }

	Graphics::DomainShaderByteCode GraphicsPipelineStateDescription::DS()
    {
		return m_domainShaderCode;
    }

    void GraphicsPipelineStateDescription::DS(Graphics::DomainShaderByteCode const& value)
    {
		m_domainShaderCode = value;
    }

	Graphics::HullShaderByteCode GraphicsPipelineStateDescription::HS()
    {
		return m_hullShaderCode;
    }

    void GraphicsPipelineStateDescription::HS(Graphics::HullShaderByteCode const& value)
    {
		m_hullShaderCode = value;
    }

	Graphics::GeometryShaderByteCode GraphicsPipelineStateDescription::GS()
    {
		return m_geometryShaderCode;
    }

    void GraphicsPipelineStateDescription::GS(Graphics::GeometryShaderByteCode const& value)
    {
		m_geometryShaderCode = value;
    }

	Graphics::StreamOutputDescription GraphicsPipelineStateDescription::StreamOutput()
    {
		return m_streamOutDescription;
    }

    void GraphicsPipelineStateDescription::StreamOutput(Graphics::StreamOutputDescription const& value)
    {
		m_streamOutDescription = value;
    }

    Graphics::BlendDescription GraphicsPipelineStateDescription::BlendState()
    {
		return m_blendState;
    }

    void GraphicsPipelineStateDescription::BlendState(Graphics::BlendDescription const& value)
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

	Graphics::RasterizerDescription GraphicsPipelineStateDescription::RasterizerState()
    {
		return m_rasterizerState;
    }

    void GraphicsPipelineStateDescription::RasterizerState(Graphics::RasterizerDescription const& value)
    {
		m_rasterizerState = value;
    }

	Graphics::DepthStencilDescription GraphicsPipelineStateDescription::DepthStencilState()
    {
        throw m_despthStencilState;
    }

    void GraphicsPipelineStateDescription::DepthStencilState(Graphics::DepthStencilDescription const& value)
    {
		m_despthStencilState = value;
    }

	Graphics::InputLayoutDescription GraphicsPipelineStateDescription::InputLayout()
    {
		return m_inputLayout;
    }

    void GraphicsPipelineStateDescription::InputLayout(Graphics::InputLayoutDescription const& value)
    {
		m_inputLayout = value;
    }

	Graphics::IndexBufferStripCut GraphicsPipelineStateDescription::IbStripCutValue()
    {
		return m_ibStripCut;
    }

    void GraphicsPipelineStateDescription::IbStripCutValue(Graphics::IndexBufferStripCut const& value)
    {
		m_ibStripCut = value;
    }

	Graphics::PrimitiveTopologyType GraphicsPipelineStateDescription::PrimitiveTopology()
    {
		return m_primitiveTopology;
    }

    void GraphicsPipelineStateDescription::PrimitiveTopology(Graphics::PrimitiveTopologyType const& value)
    {
		m_primitiveTopology = value;
    }

    uint32_t GraphicsPipelineStateDescription::NumRenderTargets()
    {
        throw hresult_not_implemented();
    }

    void GraphicsPipelineStateDescription::NumRenderTargets(uint32_t value)
    {
        throw hresult_not_implemented();
    }

    IVector<Graphics::GraphicsFormat> GraphicsPipelineStateDescription::RtvFormats()
    {
        throw hresult_not_implemented();
    }

    void GraphicsPipelineStateDescription::RtvFormats(IVector<Graphics::GraphicsFormat> const& value)
    {
        throw hresult_not_implemented();
    }

	Graphics::GraphicsFormat GraphicsPipelineStateDescription::DsvFormat()
    {
        throw hresult_not_implemented();
    }

    void GraphicsPipelineStateDescription::DsvFormat(Graphics::GraphicsFormat const& value)
    {
        throw hresult_not_implemented();
    }

	Graphics::SampleDescription GraphicsPipelineStateDescription::Samples()
    {
        throw hresult_not_implemented();
    }

    void GraphicsPipelineStateDescription::Samples(Graphics::SampleDescription const& value)
    {
        throw hresult_not_implemented();
    }
}
