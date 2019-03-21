#pragma once

#include "BlendDescription.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct BlendDescription : BlendDescriptionT<BlendDescription>
    {
        BlendDescription();

        bool AlphaToCoverageEnable();
        void AlphaToCoverageEnable(bool value);
        bool IndependentBlendEnable();
        void IndependentBlendEnable(bool value);

        Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::RenderTargetBlendDescription> RenderTargets();
        void RenderTargets(Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::RenderTargetBlendDescription> const& value);


        protected:

        Windows::Foundation::Collections::IVector<UniqueCreator::Graphics::RenderTargetBlendDescription> m_renderTargets;
        

    };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct BlendDescription : BlendDescriptionT < BlendDescription, winrt::UniqueCreator::Graphics::implementation::BlendDescription >
    {

    };
}

