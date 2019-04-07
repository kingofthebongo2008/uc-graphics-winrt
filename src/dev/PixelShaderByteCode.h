#pragma once

#include "PixelShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct PixelShaderByteCode : PixelShaderByteCodeT<PixelShaderByteCode>
    {
        PixelShaderByteCode();

        IVector<uint8_t> Code();
        void Code(IVector<uint8_t> const& value);

        IVector<uint8_t>		m_code;

        std::vector<uint8_t>    m_nativeCode;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct PixelShaderByteCode : PixelShaderByteCodeT<PixelShaderByteCode, implementation::PixelShaderByteCode>
    {
    };
}
