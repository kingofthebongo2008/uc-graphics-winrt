﻿#include "pch.h"
#include "BlendDescription.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    BlendDescription::BlendDescription()
    {
        std::vector<RenderTargetBlendDescription> values;
        m_renderTargets = single_threaded_vector< RenderTargetBlendDescription >(std::move(values));
    }

    bool BlendDescription::AlphaToCoverageEnable()
    {
        return true;
    }

    void BlendDescription::AlphaToCoverageEnable(bool value)
    {

    }

    bool BlendDescription::IndependentBlendEnable()
    {
        return true;
    }

    void BlendDescription::IndependentBlendEnable(bool value)
    {

    }

    Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::RenderTargetBlendDescription> BlendDescription::RenderTargets()
    {
        return m_renderTargets;
    }

    void BlendDescription::RenderTargets(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::RenderTargetBlendDescription> const& value)
    {
        m_renderTargets = value;
    }
}
