#pragma once

#include "winrt/UniqueCreator.Graphics.h"
#include "IFenceHandleNative.h"

#include "uc/gx/dx12/dx12.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct FenceHandle : implements<FenceHandle, IFenceHandle, IFenceHandleNative >
    {
        FenceHandle( std::unique_ptr<uc::gx::dx12::gpu_fence> fence );

        uc::gx::dx12::gpu_fence* GetFenceHandle();

    private:
        std::unique_ptr<uc::gx::dx12::gpu_fence> m_fence;
   };  
}


