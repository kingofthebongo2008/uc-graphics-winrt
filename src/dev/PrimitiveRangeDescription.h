#pragma once

#include "PrimitiveRangeDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;
    struct PrimitiveRangeDescription : PrimitiveRangeDescriptionT<PrimitiveRangeDescription>
    {
        PrimitiveRangeDescription() = delete;

        IVector<UniqueCreator::Graphics::InputElementDescription> Ranges();
        void Ranges(IVector<UniqueCreator::Graphics::InputElementDescription> const& value);
    };
}
