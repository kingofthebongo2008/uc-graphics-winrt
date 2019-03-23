#pragma once

#include "ComputeShaderByteCode.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ComputeShaderByteCode : ComputeShaderByteCodeT<ComputeShaderByteCode>
    {
        ComputeShaderByteCode() = default;

        Windows::Foundation::Collections::IVector<uint8_t> Code();
        void Code(Windows::Foundation::Collections::IVector<uint8_t> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ComputeShaderByteCode : ComputeShaderByteCodeT<ComputeShaderByteCode, implementation::ComputeShaderByteCode>
    {
    };
}
