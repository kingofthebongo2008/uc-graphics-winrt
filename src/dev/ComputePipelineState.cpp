#include "pch.h"
#include "ComputePipelineState.h"

#include "IShaderByteCodeNative.h"
#include "IResourceCreateContextNative.h"

#include "shaders/default_compute_signature.h"


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

        static D3D12_SHADER_BYTECODE create_shader_byte_code(const Blob* s)
        {
            D3D12_SHADER_BYTECODE r = {};
            r.pShaderBytecode = s->m_code;
            r.BytecodeLength = s->m_code_size;
            return r;
        }


        static D3D12_COMPUTE_PIPELINE_STATE_DESC create_compute_pipeline_state_internal(ID3D12RootSignature* s, const Blob* b)
        {
            D3D12_COMPUTE_PIPELINE_STATE_DESC r = {};
            r.CS = create_shader_byte_code(b);
            r.pRootSignature = s;
            return r;
        }
    }
    
    ComputePipelineState::ComputePipelineState(UniqueCreator::Graphics::ResourceCreateContext const& ctx, UniqueCreator::Graphics::ComputePipelineStateDescription const& d)
    {
        /*
        using namespace uc::gx::dx12;

        auto nativeCode = d.CS().as<IShaderByteCodeNative>();
        auto native     = ctx.as<IResourceCreateContextNative>();
        auto device     = native->GetDevice();
        

        Microsoft::WRL::ComPtr<ID3D12PipelineState> m_cached_pipeline_state;
        Microsoft::WRL::ComPtr<ID3D12RootSignature> m_cached_root_signature;
        uc::gx::dx12::root_signature_meta_data      m_root_signature_meta_data;
        uc::gx::dx12::compute_pipeline_state        m_pipeline_state;

        winrt::com_ptr<ID3D12Device>                device;

        auto sig                                    = create_default_compute_signature(device);
        auto blob                                   = default_compute_signature();
        auto codeBlob                               = nativeCode->GetShaderByteCode();
        auto description                            = create_compute_pipeline_state_internal(sig, &codeBlob);

        root_signature_meta_data                meta_data = parse_root_signature(blob.code(), blob.code_size(), r->null_cbv(), r->null_srv(), r->null_uav(), r->null_sampler());
        Microsoft::WRL::ComPtr<ID3D12PipelineState> state = create_compute_pipeline_state(device, &description);
        */
        throw hresult_not_implemented();
    }

    void ComputePipelineState::GetCachedBlob()
    {
        throw hresult_not_implemented();
    }
}
