#include "pch.h"
#include "UniqueCreator.Graphics.Gpu.FenceHandle.h"


namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    FenceHandle::FenceHandle( uc::gx::dx12::gpu_fence fence ) : m_fence(fence)
    {
        m_fence.m_fence->AddRef();
    }

    FenceHandle::~FenceHandle()
    {
        m_fence.m_fence->Release();
    }

    uc::gx::dx12::gpu_fence* FenceHandle::GetFenceHandle()
    {
        return nullptr;
    }
}
