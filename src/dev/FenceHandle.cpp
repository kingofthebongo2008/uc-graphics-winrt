#include "pch.h"
#include "FenceHandle.h"


namespace winrt::UniqueCreator::Graphics::implementation
{
    FenceHandle::FenceHandle( std::unique_ptr<uc::gx::dx12::gpu_fence> fence ) : m_fence(std::move(fence))
    {

    }

    uc::gx::dx12::gpu_fence* FenceHandle::GetFenceHandle()
    {
        return nullptr;
    }
}
