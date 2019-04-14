#include "pch.h"
#include "GeometryShaderByteCode.h"

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

	GeometryShaderByteCode::GeometryShaderByteCode() : m_code(std::vector<uint8_t>())
	{

	}

	IVector<uint8_t> GeometryShaderByteCode::Code()
	{
		return m_code;
	}

	void GeometryShaderByteCode::Code(IVector<uint8_t> const& value)
	{
		m_code.get_container() = toNative(value);
	}

	Blob GeometryShaderByteCode::GetShaderByteCode()
	{
		return { &m_code.get_container()[0], m_code.get_container().size() };
	}

}
