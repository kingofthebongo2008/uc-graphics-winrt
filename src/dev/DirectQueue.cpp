#include "pch.h"
#include "DirectQueue.h"


namespace winrt::UniqueCreator::Graphics::implementation
{
    HRESULT DirectQueue::WaitForIdleGpu() noexcept
    {
        return S_OK;
    }

    HRESULT DirectQueue::WaitForFence(UniqueCreator::Graphics::IFenceHandle const& v)  noexcept
    {
        return S_OK;
    }

    HRESULT DirectQueue::InsertWaitOn(UniqueCreator::Graphics::IFenceHandle const& v) noexcept
    {
        return S_OK;
    }
}