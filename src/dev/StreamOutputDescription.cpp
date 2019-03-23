#include "pch.h"
#include "StreamOutputDescription.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::StreamOutputDeclarationEntry> StreamOutputDescription::SODeclaration()
    {
        throw hresult_not_implemented();
    }

    void StreamOutputDescription::SODeclaration(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::StreamOutputDeclarationEntry> const& value)
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::Collections::IVector<uint32_t> StreamOutputDescription::BufferStrides()
    {
        throw hresult_not_implemented();
    }

    void StreamOutputDescription::BufferStrides(Windows::Foundation::Collections::IVector<uint32_t> const& value)
    {
        throw hresult_not_implemented();
    }

    uint32_t StreamOutputDescription::RasterizedStream()
    {
        throw hresult_not_implemented();
    }

    void StreamOutputDescription::RasterizedStream(uint32_t value)
    {
        throw hresult_not_implemented();
    }
}
