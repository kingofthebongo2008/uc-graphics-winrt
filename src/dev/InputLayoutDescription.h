#pragma once

#include "InputLayoutDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;

    struct InputLayoutDescription : InputLayoutDescriptionT<InputLayoutDescription>
    {
        InputLayoutDescription() = delete;

        IVector<UniqueCreator::Graphics::InputElementDescription> InputElementDescs();
        void InputElementDescs(IVector<UniqueCreator::Graphics::InputElementDescription> const& value);
    };
}
