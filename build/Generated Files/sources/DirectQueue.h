#pragma once

#include "DirectQueue.g.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct DirectQueue : DirectQueueT<DirectQueue>
    {
        DirectQueue() = default;

        HRESULT WaitForIdleGpu();
        HRESULT WaitForFence(UniqueCreator::Graphics::IFenceHandle const& v);
        HRESULT InsertWaitOn(UniqueCreator::Graphics::IFenceHandle const& v);
    };
}

namespace winrt::UniqueCreator::Graphics::factory_implementation
{
    struct DirectQueue : DirectQueueT<DirectQueue, implementation::DirectQueue>
    {
    };
}
