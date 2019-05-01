#pragma once
#include "UniqueCreator.Graphics.Gpu.SubresourceData.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct SubresourceData : SubresourceDataT<SubresourceData>
    {
        SubresourceData() = default;

		Windows::Foundation::Collections::IVector<uint8_t> Data();
        void Data(Windows::Foundation::Collections::IVector<uint8_t> value);

        uint64_t RowPitch();
        void RowPitch(uint64_t value);

        uint64_t SlicePitch();
        void SlicePitch(uint64_t value);

		private:

		uint64_t										   m_row_pitch = 0;
		uint64_t										   m_slice_pitch = 0;
		Windows::Foundation::Collections::IVector<uint8_t> m_data;
    };
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
	struct SubresourceData : SubresourceDataT<SubresourceData, implementation::SubresourceData>
	{
	};
}
