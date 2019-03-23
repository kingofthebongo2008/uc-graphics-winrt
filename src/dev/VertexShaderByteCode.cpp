#include "pch.h"
#include "VertexShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
        std::vector<uint8_t> toNative(Windows::Foundation::Collections::IVector<uint8_t> const& value)
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
        m_nativeCode = toNative(value); //double the memory
    }
}
