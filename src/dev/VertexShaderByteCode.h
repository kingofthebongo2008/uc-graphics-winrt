#pragma once

#include "VertexShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct VertexShaderByteCode : VertexShaderByteCodeT<VertexShaderByteCode>
    {
        VertexShaderByteCode() = default;

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct VertexShaderByteCode : VertexShaderByteCodeT<VertexShaderByteCode, implementation::VertexShaderByteCode>
    {
    };
}
