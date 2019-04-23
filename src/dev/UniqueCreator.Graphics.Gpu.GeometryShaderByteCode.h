#pragma once

#include "UniqueCreator.Graphics.Gpu.GeometryShaderByteCode.g.h"

#include "IShaderByteCodeNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace Windows::Foundation::Collections;

	struct GeometryShaderByteCode : GeometryShaderByteCodeT<GeometryShaderByteCode, IShaderByteCodeNative>
	{
		GeometryShaderByteCode();


		IVector<uint8_t> Code();
		void Code(IVector<uint8_t> const& value);
		Blob GetShaderByteCode();
		using vector = impl::input_vector<uint8_t, std::vector<uint8_t, std::allocator<uint8_t> > >;
		vector m_code;
	};
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
	struct GeometryShaderByteCode : GeometryShaderByteCodeT<GeometryShaderByteCode, implementation::GeometryShaderByteCode>
	{
	};
}
