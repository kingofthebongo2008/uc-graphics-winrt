#pragma once

#include "PrimitiveRangeDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	using namespace Windows::Foundation::Collections;
    struct PrimitiveRangeDescription : PrimitiveRangeDescriptionT<PrimitiveRangeDescription>
    {
		PrimitiveRangeDescription();

        IVector<InputElementDescription> Ranges();
        void Ranges(IVector<InputElementDescription> const& value);

		IVector< InputElementDescription > m_ranges;
    };
}
