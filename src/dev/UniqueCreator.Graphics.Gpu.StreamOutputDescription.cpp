#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.StreamOutputDescription.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	StreamOutputDescription::StreamOutputDescription() :
	m_so(single_threaded_vector<StreamOutputDeclarationEntry>())
	, m_strides(single_threaded_vector<uint32_t>())
	{

	}

    IVector<StreamOutputDeclarationEntry> StreamOutputDescription::SODeclaration()
    {
		return m_so;
    }

    void StreamOutputDescription::SODeclaration(IVector<StreamOutputDeclarationEntry> const& value)
    {
		m_so = value;
    }

    IVector<uint32_t> StreamOutputDescription::BufferStrides()
    {
		return m_strides;
    }

    void StreamOutputDescription::BufferStrides(IVector<uint32_t> const& value)
    {
		m_strides = value;
    }

    uint32_t StreamOutputDescription::RasterizedStream()
    {
		return m_rasterized_stream;
    }

    void StreamOutputDescription::RasterizedStream(uint32_t value)
    {
		m_rasterized_stream = value;
    }
}
