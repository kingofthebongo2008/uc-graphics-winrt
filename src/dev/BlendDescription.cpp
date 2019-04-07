#include "pch.h"
#include "BlendDescription.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    BlendDescription::BlendDescription()
    {
        m_renderTargets = single_threaded_vector< RenderTargetBlendDescription >(std::vector<RenderTargetBlendDescription>());
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

    IVector<RenderTargetBlendDescription> BlendDescription::RenderTargets()
    {
        return m_renderTargets;
    }

    void BlendDescription::RenderTargets(IVector<RenderTargetBlendDescription> const& value)
    {
        m_renderTargets = value;
    }
}
