#pragma once

#include "HullShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode>
    {
        HullShaderByteCode();

        IVector<uint8_t> Code();
        void Code(IVector<uint8_t> const& value);

        IVector<uint8_t>	 m_code;
        std::vector<uint8_t> m_nativeCode;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode, implementation::HullShaderByteCode>
    {
    };
}
