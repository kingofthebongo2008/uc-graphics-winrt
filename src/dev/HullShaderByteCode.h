#pragma once

#include "HullShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode>
    {
        HullShaderByteCode();

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
        Windows::Foundation::Collections::IVector<uint8_t> m_code;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode, implementation::HullShaderByteCode>
    {
    };
}
