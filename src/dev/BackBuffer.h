#pragma once

#include "winrt/UniqueCreator.Graphics.h"
#include "IBackBufferNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    struct BackBuffer : implements<BackBuffer, IBackBuffer, IBackBufferNative >
    {
        BackBuffer() = default;

        private:
   };  
}

