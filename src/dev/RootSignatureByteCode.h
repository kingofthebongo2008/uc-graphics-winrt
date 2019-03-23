#pragma once

#include "RootSignatureByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct RootSignatureByteCode : RootSignatureByteCodeT<RootSignatureByteCode>
    {
        RootSignatureByteCode() = default;

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct RootSignatureByteCode : RootSignatureByteCodeT<RootSignatureByteCode, implementation::RootSignatureByteCode>
    {
    };
}
