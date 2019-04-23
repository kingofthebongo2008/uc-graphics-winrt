#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include "IFenceHandleNative.h"

#include "uc/gx/dx12/dx12.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct FenceHandle : implements<FenceHandle, IFenceHandle, IFenceHandleNative >
    {
        FenceHandle( uc::gx::dx12::gpu_fence fence);
        ~FenceHandle();

        uc::gx::dx12::gpu_fence* GetFenceHandle();

        void Dummy() {}
    private:

        uc::gx::dx12::gpu_fence m_fence;
        FenceHandle(const FenceHandle&);
        FenceHandle& operator=(const FenceHandle&);


   };  
}


