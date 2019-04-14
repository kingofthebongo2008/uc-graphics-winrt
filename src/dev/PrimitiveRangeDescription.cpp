﻿#include "pch.h"
#include "PrimitiveRangeDescription.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
	PrimitiveRangeDescription::PrimitiveRangeDescription() : m_ranges( single_threaded_vector<InputElementDescription> () )
	{
		
	}

    IVector<InputElementDescription> PrimitiveRangeDescription::Ranges()
    {
		return m_ranges;
    }

    void PrimitiveRangeDescription::Ranges(IVector<InputElementDescription> const& value)
    {
		m_ranges = value;
    }
}
