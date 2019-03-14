#include "pch.h"
#include "DirectQueue.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    HRESULT DirectQueue::WaitForIdleGpu()
    {
        throw hresult_not_implemented();
    }

    HRESULT DirectQueue::WaitForFence(UniqueCreator::Graphics::IFenceHandle const& v)
    {
        throw hresult_not_implemented();
    }

    HRESULT DirectQueue::InsertWaitOn(UniqueCreator::Graphics::IFenceHandle const& v)
    {
        throw hresult_not_implemented();
    }
}
