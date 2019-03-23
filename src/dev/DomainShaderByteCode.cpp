#include "pch.h"
#include "DomainShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    DomainShaderByteCode::DomainShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> DomainShaderByteCode::Code()
    {
        return m_code;
    }

    void DomainShaderByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
