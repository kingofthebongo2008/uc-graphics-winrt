#include "pch.h"
#include "ComputeShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    ComputeShaderByteCode::ComputeShaderByteCode()
    {
        m_code = single_threaded_vector< uint8_t >(std::vector<uint8_t>());
    }

    Windows::Foundation::Collections::IVector<uint8_t> ComputeShaderByteCode::Code()
    {
        return m_code;
    }

    void ComputeShaderByteCode::Code(Windows::Foundation::Collections::IVector<uint8_t> const& value)
    {
        m_code = value;
    }
}
