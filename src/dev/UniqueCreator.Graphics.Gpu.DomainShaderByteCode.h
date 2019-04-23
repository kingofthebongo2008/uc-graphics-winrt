#pragma once

#include "UniqueCreator.Graphics.Gpu.DomainShaderByteCode.g.h"

#include "IShaderByteCodeNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace Windows::Foundation::Collections;

	struct DomainShaderByteCode : DomainShaderByteCodeT<DomainShaderByteCode, IShaderByteCodeNative>
	{
		DomainShaderByteCode();


		IVector<uint8_t> Code();
		void Code(IVector<uint8_t> const& value);
		Blob GetShaderByteCode();
		using vector = impl::input_vector<uint8_t, std::vector<uint8_t, std::allocator<uint8_t> > >;
		vector m_code;
	};
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
	struct DomainShaderByteCode : DomainShaderByteCodeT<DomainShaderByteCode, implementation::DomainShaderByteCode>
	{
	};
}
