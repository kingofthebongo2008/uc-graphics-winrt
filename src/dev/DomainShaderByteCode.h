#pragma once

#include "DomainShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct DomainShaderByteCode : DomainShaderByteCodeT<DomainShaderByteCode>
    {
        DomainShaderByteCode();

        IVector<uint8_t> Code();
        void Code(IVector<uint8_t> const& value);

        IVector<uint8_t>	m_code;
        std::vector<uint8_t> m_nativeCode;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct DomainShaderByteCode : DomainShaderByteCodeT<DomainShaderByteCode, implementation::DomainShaderByteCode>
    {
    };
}
