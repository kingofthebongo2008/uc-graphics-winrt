#pragma once

#pragma warning(disable:4100)

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#endif

#include <unknwn.h>

#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Graphics.Display.h>

#include <winrt/Windows.UI.Xaml.Controls.h>
#include <Windows.UI.Xaml.Media.DXInterop.h>

#include <wrl/client.h>

#include <d3d12.h>
