#pragma once

#include "PrimitiveRangeDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct PrimitiveRangeDescription : PrimitiveRangeDescriptionT<PrimitiveRangeDescription>
    {
        PrimitiveRangeDescription() = delete;

        Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::InputElementDescription> Ranges();
        void Ranges(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::InputElementDescription> const& value);
    };
}
