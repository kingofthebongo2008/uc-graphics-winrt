#pragma once

#include "InputLayoutDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct InputLayoutDescription : InputLayoutDescriptionT<InputLayoutDescription>
    {
        InputLayoutDescription() = delete;

        Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::InputElementDescription> InputElementDescs();
        void InputElementDescs(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::InputElementDescription> const& value);
    };
}
