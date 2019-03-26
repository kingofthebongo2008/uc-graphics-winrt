#pragma once
#include <windows.foundation.h>
#include <d3d12.h>

namespace uc
{
    namespace gx
    {
        namespace dx12
        {
            class gpu_resource_create_context;
        }
    }
}

namespace winrt::UniqueCreator::Graphics
{

    struct __declspec(uuid("76CBCE58-DE24-4B9D-94D2-B4BB687B6A3E")) __declspec(novtable) IResourceCreateContextNative : ::IUnknown
    {
        virtual ID3D12Device* GetDevice( ) = 0;
        virtual uc::gx::dx12::gpu_resource_create_context* GetResourceCreateContext() = 0;
    };
}
