#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.PixelShaderByteCode.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
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

	PixelShaderByteCode::PixelShaderByteCode() : m_code(std::vector<uint8_t>())
	{

	}

	IVector<uint8_t> PixelShaderByteCode::Code()
	{
		return m_code;
	}

	void PixelShaderByteCode::Code(IVector<uint8_t> const& value)
	{
		m_code.get_container() = toNative(value);
	}

	Blob PixelShaderByteCode::GetShaderByteCode()
	{
		return { &m_code.get_container()[0], m_code.get_container().size() };
	}

}
