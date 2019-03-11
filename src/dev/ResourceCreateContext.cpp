#include "pch.h"
#include "ResourceCreateContext.h"
#include <windows.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    hstring ResourceCreateContext::Text()
    {
        return L"Button1";
    }

    HRESULT __stdcall ResourceCreateContext::GetDevice( ID3D12Device** d ) noexcept
    {
        *d = m_device.get();
        (*d)->AddRef();
        return S_OK;
    }

    ResourceCreateContext::ResourceCreateContext()
    {
        HRESULT r = D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_12_1, __uuidof(ID3D12Device4), (void**) m_device.put());

        if (FAILED(r))
        {
            __debugbreak();
        }

    }
}
