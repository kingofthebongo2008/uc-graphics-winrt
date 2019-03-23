#include "pch.h"
#include "HullShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    HullShaderByteCode::HullShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> HullShaderByteCode::Code()
    {
        return m_code;
    }

    void HullShaderByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
