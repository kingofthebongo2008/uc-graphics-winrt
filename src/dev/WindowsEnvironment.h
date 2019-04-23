#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    Size2D BuildSwapChainSize(Size2D logicalSize, const winrt::Windows::Graphics::Display::DisplayInformation& displayInformation, float compositionScaleX = 1.0f, float compositionScaleY = 1.0f);

    inline Size2D toSize2D(const Windows::Foundation::Rect r)
    {
        return Size2D{ r.Width, r.Height };
    }
}
