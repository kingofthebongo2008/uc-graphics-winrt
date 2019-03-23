#pragma once

#include "RootSignatureByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct RootSignatureByteCode : RootSignatureByteCodeT<RootSignatureByteCode>
    {
        RootSignatureByteCode();

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
        Windows::Foundation::Collections::IVector<uint8_t> m_code;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct RootSignatureByteCode : RootSignatureByteCodeT<RootSignatureByteCode, implementation::RootSignatureByteCode>
    {
    };
}
