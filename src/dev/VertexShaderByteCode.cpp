#include "pch.h"
#include "VertexShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    VertexShaderByteCode::VertexShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> VertexShaderByteCode::Code()
    {
        return m_code;
    }

    void VertexShaderByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
