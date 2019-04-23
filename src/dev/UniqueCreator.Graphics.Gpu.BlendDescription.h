#pragma once

#include "UniqueCreator.Graphics.Gpu.BlendDescription.g.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace Windows::Foundation::Collections;

    struct BlendDescription : BlendDescriptionT<BlendDescription>
    {
        BlendDescription();

        bool AlphaToCoverageEnable();
        void AlphaToCoverageEnable(bool value);
        bool IndependentBlendEnable();
        void IndependentBlendEnable(bool value);

		IVector<RenderTargetBlendDescription> RenderTargets();
        void RenderTargets(IVector<RenderTargetBlendDescription> const& value);


        protected:

		IVector<RenderTargetBlendDescription> m_renderTargets;

		bool m_alphaToCoverageEnable = false;
		bool m_independentBlendEnable = false;
    };  
}

namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct BlendDescription : BlendDescriptionT < BlendDescription, implementation::BlendDescription >
    {

    };
}

