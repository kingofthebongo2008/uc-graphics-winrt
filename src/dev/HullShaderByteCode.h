#pragma once

#include "HullShaderByteCode.g.h"

#include "IShaderByteCodeNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

	struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode, IShaderByteCodeNative>
	{
		HullShaderByteCode();


		IVector<uint8_t> Code();
		void Code(IVector<uint8_t> const& value);
		Blob GetShaderByteCode();
		using vector = impl::input_vector<uint8_t, std::vector<uint8_t, std::allocator<uint8_t> > >;
		vector m_code;
	};
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
	struct HullShaderByteCode : HullShaderByteCodeT<HullShaderByteCode, implementation::HullShaderByteCode>
	{
	};
}
