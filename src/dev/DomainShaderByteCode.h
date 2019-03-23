#pragma once

#include "DomainShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct DomainShaderByteCode : DomainShaderByteCodeT<DomainShaderByteCode>
    {
        DomainShaderByteCode();

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
        Windows::Foundation::Collections::IVector<uint8_t> m_code;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct DomainShaderByteCode : DomainShaderByteCodeT<DomainShaderByteCode, implementation::DomainShaderByteCode>
    {
    };
}
