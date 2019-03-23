#include "pch.h"
#include "PixelShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    PixelShaderByteCode::PixelShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> PixelShaderByteCode::Code()
    {
        return m_code;
    }

    void PixelShaderByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
