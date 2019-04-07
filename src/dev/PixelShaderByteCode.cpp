﻿#include "pch.h"
#include "PixelShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
        std::vector<uint8_t> toNative(IVector<uint8_t> const& value)
        {
            std::vector<uint8_t> v;

            v.reserve(value.Size());

            for (auto i : value)
            {
                v.push_back(i);
            }

            return v;
        }
    }

    PixelShaderByteCode::PixelShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    IVector<uint8_t> PixelShaderByteCode::Code()
    {
        return m_code;
    }

    void PixelShaderByteCode::Code(IVector<uint8_t> const& value)
    {
        m_code = value;
        m_nativeCode = toNative(value); //double the memory
    }
}
