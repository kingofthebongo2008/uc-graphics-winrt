﻿#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.RootSignatureByteCode.h"

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

	RootSignatureByteCode::RootSignatureByteCode() : m_code(std::vector<uint8_t>())
	{

	}

	IVector<uint8_t> RootSignatureByteCode::Code()
	{
		return m_code;
	}

	void RootSignatureByteCode::Code(IVector<uint8_t> const& value)
	{
		m_code.get_container() = toNative(value);
	}

	Blob RootSignatureByteCode::GetShaderByteCode()
	{
		return { &m_code.get_container()[0], m_code.get_container().size() };
	}

}
