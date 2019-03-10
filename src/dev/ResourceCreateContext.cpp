#include "pch.h"
#include "ResourceCreateContext.h"
#include <windows.h>

namespace winrt::UniqueCreator::Graphics::implementation
{

    hstring ResourceCreateContext::Text()
    {
        return L"Button1";
    }

    HRESULT  ResourceCreateContext::Call()
    {
        return E_FAIL;
    }

}
