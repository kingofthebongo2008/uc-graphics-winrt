#include "pch.h"
#include "ComputePipelineState.h"

#include "IShaderByteCodeNative.h"
#include "IResourceCreateContextNative.h"



namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
        /*
        Microsoft::WRL::ComPtr<ID3D12PipelineState> m_cached_pipeline_state;
        Microsoft::WRL::ComPtr<ID3D12RootSignature> m_cached_root_signature;
        uc::gx::dx12::root_signature_meta_data      m_root_signature_meta_data;
        uc::gx::dx12::compute_pipeline_state        m_pipeline_state;

        std::unique_ptr<ComputePipelineState>   ResourceCreateContext::Impl::CreateComputePipelineState(const ComputePipelineStateDescription* desc)
        {
            auto r = rc();
            auto d = m_device.Get();

            using namespace uc::gx::dx12;

            auto sig = create_default_graphics_signature(d);
            auto blob = default_graphics_signature();
            auto description = create_compute_pipeline_state_internal(sig, desc);

            root_signature_meta_data                meta_data = parse_root_signature(blob.code(), blob.code_size(), r->null_cbv(), r->null_srv(), r->null_uav(), r->null_sampler());
            Microsoft::WRL::ComPtr<ID3D12PipelineState> state = create_compute_pipeline_state(d, &description);

            return std::make_unique<ComputePipelineStateInternal>(state, sig, meta_data);
        }
        */
    }
    
    ComputePipelineState::ComputePipelineState(UniqueCreator::Graphics::ResourceCreateContext const& ctx, UniqueCreator::Graphics::ComputePipelineStateDescription const& d)
    {
        using namespace uc::gx::dx12;

        auto nativeCode = d.CS().as<IShaderByteCodeNative>();
        auto native     = ctx.as<IResourceCreateContextNative>();
        /*

        Microsoft::WRL::ComPtr<ID3D12PipelineState> m_cached_pipeline_state;
        Microsoft::WRL::ComPtr<ID3D12RootSignature> m_cached_root_signature;
        uc::gx::dx12::root_signature_meta_data      m_root_signature_meta_data;
        uc::gx::dx12::compute_pipeline_state        m_pipeline_state;

        winrt::com_ptr<ID3D12Device> device;
        HRESULT hr = native->GetDevice(device.put());

        
        auto sig = create_default_graphics_signature(d);
        auto blob = default_graphics_signature();
        auto description = create_compute_pipeline_state_internal(sig, desc);

        root_signature_meta_data                meta_data = parse_root_signature(blob.code(), blob.code_size(), r->null_cbv(), r->null_srv(), r->null_uav(), r->null_sampler());
        Microsoft::WRL::ComPtr<ID3D12PipelineState> state = create_compute_pipeline_state(d, &description);

        */

        throw hresult_not_implemented();
        
    }

    void ComputePipelineState::GetCachedBlob()
    {
        throw hresult_not_implemented();
    }
}
