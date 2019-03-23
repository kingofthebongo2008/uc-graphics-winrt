#pragma once

#include "PixelShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct PixelShaderByteCode : PixelShaderByteCodeT<PixelShaderByteCode>
    {
        PixelShaderByteCode() = default;

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct PixelShaderByteCode : PixelShaderByteCodeT<PixelShaderByteCode, implementation::PixelShaderByteCode>
    {
    };
}
