#pragma once

#include "BlendDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
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
    };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct BlendDescription : BlendDescriptionT < BlendDescription, winrt::UniqueCreator::Graphics::implementation::BlendDescription >
    {

    };
}

