#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.BlendDescription.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    BlendDescription::BlendDescription() :
	m_renderTargets( single_threaded_vector< RenderTargetBlendDescription >(std::vector<RenderTargetBlendDescription>()))
    {
        
    }

    bool BlendDescription::AlphaToCoverageEnable()
    {
		return m_alphaToCoverageEnable;
    }

    void BlendDescription::AlphaToCoverageEnable(bool value)
    {
		m_alphaToCoverageEnable = value;
    }

    bool BlendDescription::IndependentBlendEnable()
    {
		return m_independentBlendEnable;
    }

    void BlendDescription::IndependentBlendEnable(bool value)
    {
		m_independentBlendEnable = value;
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
