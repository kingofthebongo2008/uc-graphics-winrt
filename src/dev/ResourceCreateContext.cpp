#include "pch.h"
#include "ResourceCreateContext.h"
#include <windows.h>

namespace winrt::UniqueCreator::Graphics::implementation
{
    hstring ResourceCreateContext::Text()
    {
        return L"Button1";
    }

    HRESULT  ResourceCreateContext::Call() noexcept
    {
        return S_OK;
    }

    ResourceCreateContext::ResourceCreateContext()
    {
        IResourceCreateContext* r = nullptr;
        this->QueryInterface(__uuidof(IResourceCreateContextNative), reinterpret_cast<void**>(&r));

        if (r)
        {
            __debugbreak();
        }
        else
        {
            __debugbreak();
        }
    }
}
