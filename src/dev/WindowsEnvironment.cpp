#include "pch.h"

#include <dxgi1_6.h>

#include "WindowsEnvironment.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    namespace
    {
        DXGI_MODE_ROTATION compute_display_rotation(winrt::Windows::Graphics::Display::DisplayOrientations native_orientation, winrt::Windows::Graphics::Display::DisplayOrientations current_orientation)
        {
            using namespace winrt::Windows::Graphics::Display;

            DXGI_MODE_ROTATION rotation = DXGI_MODE_ROTATION_UNSPECIFIED;

            // Note: NativeOrientation can only be Landscape or Portrait even though
            // the DisplayOrientations enum has other values.
            switch (native_orientation)
            {
            case DisplayOrientations::Landscape:
                switch (current_orientation)
                {
                case DisplayOrientations::Landscape:
                    rotation = DXGI_MODE_ROTATION_IDENTITY;
                    break;

                case DisplayOrientations::Portrait:
                    rotation = DXGI_MODE_ROTATION_ROTATE270;
                    break;

                case DisplayOrientations::LandscapeFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE180;
                    break;

                case DisplayOrientations::PortraitFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE90;
                    break;
                }
                break;

            case DisplayOrientations::Portrait:
                switch (current_orientation)
                {
                case DisplayOrientations::Landscape:
                    rotation = DXGI_MODE_ROTATION_ROTATE90;
                    break;

                case DisplayOrientations::Portrait:
                    rotation = DXGI_MODE_ROTATION_IDENTITY;
                    break;

                case DisplayOrientations::LandscapeFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE270;
                    break;

                case DisplayOrientations::PortraitFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE180;
                    break;
                }
                break;
            }
            return rotation;
        }

        // Converts a length in device-independent pixels (DIPs) to a length in physical pixels.
        float convert_dips_to_pixels(float dips, float dpi)
        {
            static const float dipsPerInch = 96.0f;
            return floorf(dips * dpi / dipsPerInch + 0.5f); // Round to nearest integer.
        }
    }

    Size2D BuildSwapChainSize( Size2D logicalSize, const winrt::Windows::Graphics::Display::DisplayInformation& displayInformation, float compositionScaleX, float compositionScaleY )
    {
        auto dpi = displayInformation.LogicalDpi();

        auto physical_width     = convert_dips_to_pixels(compositionScaleX * logicalSize.Width, dpi);
        auto physical_height    = convert_dips_to_pixels(compositionScaleY * logicalSize.Height, dpi);

        // Prevent small sizes DirectX content from being created.
        physical_width          = physical_width  < 8 ? 8 : physical_width;
        physical_height         = physical_height < 8 ? 8 : physical_height;

        auto display_rotation   = compute_display_rotation(displayInformation.NativeOrientation(), displayInformation.CurrentOrientation());
        bool swap_dimensions    = display_rotation == DXGI_MODE_ROTATION_ROTATE90 || display_rotation == DXGI_MODE_ROTATION_ROTATE270;

        Size2D result;

        result.Width  = swap_dimensions ? physical_height : physical_width;
        result.Height = swap_dimensions ? physical_width  : physical_height;

        return result;
    }
}
