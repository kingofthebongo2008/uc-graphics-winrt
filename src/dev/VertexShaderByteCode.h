#pragma once

#include "VertexShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct VertexShaderByteCode : VertexShaderByteCodeT<VertexShaderByteCode>
    {
        VertexShaderByteCode();

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    
        Windows::Foundation::Collections::IVector<uint8_t> m_code;

        std::vector<uint8_t>                               m_nativeCode;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct VertexShaderByteCode : VertexShaderByteCodeT<VertexShaderByteCode, implementation::VertexShaderByteCode>
    {
    };
}
