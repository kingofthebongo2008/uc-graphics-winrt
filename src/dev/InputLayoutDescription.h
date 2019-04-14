#pragma once

#include "InputLayoutDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
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

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
	struct InputLayoutDescription : InputLayoutDescriptionT < InputLayoutDescription, winrt::UniqueCreator::Graphics::implementation::InputLayoutDescription >
	{

	};
}
