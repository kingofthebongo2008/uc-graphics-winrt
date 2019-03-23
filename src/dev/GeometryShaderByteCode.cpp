#include "pch.h"
#include "GeometryShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    GeometryShaderByteCode::GeometryShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> GeometryShaderByteCode::Code()
    {
        return m_code;
    }

    void GeometryShaderByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
