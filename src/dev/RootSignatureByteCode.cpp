#include "pch.h"
#include "RootSignatureByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    RootSignatureByteCode::RootSignatureByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> RootSignatureByteCode::Code()
    {
        return m_code;
    }

    void RootSignatureByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
