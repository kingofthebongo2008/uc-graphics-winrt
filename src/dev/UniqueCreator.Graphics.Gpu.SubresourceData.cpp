#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.SubresourceData.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    Windows::Foundation::Collections::IVector<uint8_t> SubresourceData::Data()
    {
		return m_data;
    }

    void SubresourceData::Data(Windows::Foundation::Collections::IVector<uint8_t> value)
    {
		m_data = value;
    }

    uint64_t SubresourceData::RowPitch()
    {
		return m_row_pitch;
    }

    void SubresourceData::RowPitch(uint64_t value)
    {
		m_row_pitch = value;
    }

    uint64_t SubresourceData::SlicePitch()
    {
		return m_slice_pitch;
    }
    void SubresourceData::SlicePitch(uint64_t value)
    {
		m_slice_pitch = value;
    }
}
