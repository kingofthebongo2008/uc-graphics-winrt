#pragma once

#include "UniqueCreator.Graphics.Gpu.InputLayoutDescription.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace Windows::Foundation::Collections;

    struct InputLayoutDescription : InputLayoutDescriptionT<InputLayoutDescription>
    {
        InputLayoutDescription();

        IVector<InputElementDescription> InputElementDescs();
        void InputElementDescs(IVector<InputElementDescription> const& value);

		IVector<InputElementDescription> m_descriptions;
    };
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
	struct InputLayoutDescription : InputLayoutDescriptionT < InputLayoutDescription, implementation::InputLayoutDescription >
	{

	};
}
