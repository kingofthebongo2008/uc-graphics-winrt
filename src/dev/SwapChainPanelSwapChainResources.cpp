#include "pch.h"
#include "SwapChainPanelSwapChainResources.h"
#include "IResourceCreateContextNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    SwapChainPanelSwapChainResources::SwapChainPanelSwapChainResources(UniqueCreator::Graphics::ResourceCreateContext const & ctx, Windows::UI::Xaml::Controls::SwapChainPanel const & panel)
    {
        winrt::com_ptr<IResourceCreateContextNative> const dxdevice{ ctx.as<IResourceCreateContextNative>() };

        if (dxdevice)
        {
            winrt::com_ptr<ID3D12Device> device;

            HRESULT hr = dxdevice->GetDevice(device.put());

            if (SUCCEEDED(hr))
            {
                winrt::com_ptr<ISwapChainPanelNative> const p{ panel.as<ISwapChainPanelNative>() };

                HRESULT hr = dxdevice->GetDevice(device.put());
                

            }
        }
    }

    HRESULT SwapChainPanelSwapChainResources::f()
    {
        return S_OK;
    }
}
