#pragma once

#include "ResourceCreateContext.g.h"
#include "SwapChainPanelSwapChainResources.g.h"

#include <midlbase.h>

namespace winrt::UniqueCreator::Graphics
{
    struct __declspec(uuid("ddc36e02-18ac-47c4-ae17-d420eece2281")) IMyComInterface : ::IUnknown
    {
        virtual HRESULT __stdcall Call() = 0;
    };

    /*
    class IResourceCreateContextNative : public IUnknown
    {
        public:
        virtual HRESULT Call() = 0;
    };

    */
}

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct ResourceCreateContext : ResourceCreateContextT<ResourceCreateContext, IMyComInterface >
    {
        ResourceCreateContext() = default;

        
        hstring Text();

        
        HRESULT Call();
       

   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct ResourceCreateContext : ResourceCreateContextT < ResourceCreateContext, winrt::UniqueCreator::Graphics::implementation::ResourceCreateContext >
    {

    };
}
