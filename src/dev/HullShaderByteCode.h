#pragma once

#include "HullShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode>
    {
        HullShaderByteCode() = default;

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode, implementation::HullShaderByteCode>
    {
    };
}
