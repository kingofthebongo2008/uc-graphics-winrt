#pragma once

#include "StreamOutputDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct StreamOutputDescription : StreamOutputDescriptionT<StreamOutputDescription>
    {
        StreamOutputDescription() = delete;

        Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::StreamOutputDeclarationEntry> SODeclaration();
        void SODeclaration(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::StreamOutputDeclarationEntry> const& value);
        Windows::Foundation::Collections::IVector<uint32_t> BufferStrides();
        void BufferStrides(Windows::Foundation::Collections::IVector<uint32_t> const& value);
        uint32_t RasterizedStream();
        void RasterizedStream(uint32_t value);
    };
}
