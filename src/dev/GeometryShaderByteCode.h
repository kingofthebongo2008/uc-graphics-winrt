#pragma once

#include "GeometryShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct GeometryShaderByteCode : GeometryShaderByteCodeT<GeometryShaderByteCode>
    {
        GeometryShaderByteCode() = default;

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct GeometryShaderByteCode : GeometryShaderByteCodeT<GeometryShaderByteCode, implementation::GeometryShaderByteCode>
    {
    };
}
