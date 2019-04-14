#pragma once

#include "StreamOutputDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct StreamOutputDescription : StreamOutputDescriptionT<StreamOutputDescription>
    {
		StreamOutputDescription();

        IVector<StreamOutputDeclarationEntry> SODeclaration();
        void SODeclaration(IVector<StreamOutputDeclarationEntry> const& value);
        IVector<uint32_t> BufferStrides();
        void BufferStrides(IVector<uint32_t> const& value);
        uint32_t RasterizedStream();
        void RasterizedStream(uint32_t value);

		IVector<StreamOutputDeclarationEntry>		  m_so;
		IVector<uint32_t>							  m_strides;
		uint32_t									  m_rasterized_stream = 0;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
	struct StreamOutputDescription : StreamOutputDescriptionT < StreamOutputDescription, winrt::UniqueCreator::Graphics::implementation::StreamOutputDescription >
	{

	};
}

