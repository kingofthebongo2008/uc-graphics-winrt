﻿#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.InputLayoutDescription.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	InputLayoutDescription::InputLayoutDescription() : m_descriptions ( single_threaded_vector(std::vector< InputElementDescription >()) )
	{
	}

    IVector<InputElementDescription> InputLayoutDescription::InputElementDescs()
    {
		return m_descriptions;
    }

    void InputLayoutDescription::InputElementDescs(IVector<InputElementDescription> const& value)
    {
		m_descriptions = value;
    }
}
