#include "pch.h"
#include "ResourceCreateContext.h"
//#include "DirectQueue.h"

#include "uc/gx/dx12/dx12.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    HRESULT __stdcall ResourceCreateContext::GetDevice( ID3D12Device** d ) noexcept
    {
        *d = m_device.get();
        (*d)->AddRef();
        return S_OK;
    }

    uc::gx::dx12::gpu_resource_create_context* ResourceCreateContext::GetResourceCreateContext() noexcept
    {
        return m_ctx.get();
    }

    ResourceCreateContext::ResourceCreateContext()
    {
        HRESULT r = D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_12_1, __uuidof(ID3D12Device4), (void**) m_device.put());

        if (r == S_OK)
        {
            m_ctx = std::make_unique<uc::gx::dx12::gpu_resource_create_context>(m_device.get());
            //todo
        }
    }

    /*
    UniqueCreator::Graphics::DirectQueue ResourceCreateContext::CreateDirectQueue()
    {
        return DirectQueue();
    }
    */

    void ResourceCreateContext::Sync()
    {
        m_ctx->sync();
    }

    void ResourceCreateContext::ResetViewDependentResources()
    {
        m_ctx->reset_view_dependent_resources();
    }
}
