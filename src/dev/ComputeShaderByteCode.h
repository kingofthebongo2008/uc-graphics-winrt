#pragma once

#include "ComputeShaderByteCode.g.h"

#include "IShaderByteCodeNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct ComputeShaderByteCode : ComputeShaderByteCodeT<ComputeShaderByteCode, IShaderByteCodeNative>
    {
        ComputeShaderByteCode();

        IVector<uint8_t> Code();
        void Code(IVector<uint8_t> const& value);

        IVector<uint8_t> m_code;

        Blob GetShaderByteCode();
        std::vector<uint8_t>     m_nativeCode;
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ComputeShaderByteCode : ComputeShaderByteCodeT<ComputeShaderByteCode, implementation::ComputeShaderByteCode>
    {
    };
}
