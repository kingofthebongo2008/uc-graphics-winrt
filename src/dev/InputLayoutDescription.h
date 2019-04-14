#pragma once

#include "InputLayoutDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct InputLayoutDescription : InputLayoutDescriptionT<InputLayoutDescription>
    {
        InputLayoutDescription() = default;

        IVector<UniqueCreator::Graphics::InputElementDescription> InputElementDescs();
        void InputElementDescs(IVector<UniqueCreator::Graphics::InputElementDescription> const& value);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
	struct InputLayoutDescription : InputLayoutDescriptionT < InputLayoutDescription, winrt::UniqueCreator::Graphics::implementation::InputLayoutDescription >
	{

	};
}
