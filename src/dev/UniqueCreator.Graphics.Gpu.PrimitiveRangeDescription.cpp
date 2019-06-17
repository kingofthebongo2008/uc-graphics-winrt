#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.PrimitiveRangeDescription.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
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
