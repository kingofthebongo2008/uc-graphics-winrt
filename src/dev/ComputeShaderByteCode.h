#pragma once

#include "ComputeShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ComputeShaderByteCode : ComputeShaderByteCodeT<ComputeShaderByteCode>
    {
        ComputeShaderByteCode();

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);

        Windows::Foundation::Collections::IVector<uint8_t> m_code;

        std::vector<uint8_t>                               m_nativeCode;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ComputeShaderByteCode : ComputeShaderByteCodeT<ComputeShaderByteCode, implementation::ComputeShaderByteCode>
    {
    };
}
