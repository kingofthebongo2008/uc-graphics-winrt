#pragma once

#include "DirectQueue.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct DirectQueue : DirectQueueT<DirectQueue>
    {
        DirectQueue() = default;
        

        HRESULT WaitForIdleGpu() noexcept;
        HRESULT WaitForFence(UniqueCreator::Graphics::IFenceHandle const& v)  noexcept;
        HRESULT InsertWaitOn(UniqueCreator::Graphics::IFenceHandle const& v) noexcept;

    private:
   };  
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct DirectQueue : DirectQueueT < DirectQueue, winrt::UniqueCreator::Graphics::implementation::DirectQueue >
    {

    };
}
