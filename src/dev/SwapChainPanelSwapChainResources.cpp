#include "pch.h"
#include "SwapChainPanelSwapChainResources.h"
#include "IResourceCreateContextNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    template <typename T>
    T convert_from_abi(::IUnknown* from)
    {
        T to{ nullptr };

        winrt::check_hresult(from->QueryInterface(winrt::guid_of<T>(),
            reinterpret_cast<void**>(winrt::put_abi(to))));

        return to;
    }

    SwapChainPanelSwapChainResources::SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const& ctx)
    {
        winrt::com_ptr<IResourceCreateContextNative> const dxdevice{ ctx.as<IResourceCreateContextNative>() };

        if (dxdevice)
        {
            auto t = dxdevice.try_as < IResourceCreateContextNative >();

            if (t)
            {
                dxdevice->Call();
            }
        }
    }

    HRESULT SwapChainPanelSwapChainResources::f()
    {
        return S_OK;
    }
}
