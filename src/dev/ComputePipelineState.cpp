#include "pch.h"
#include "ComputePipelineState.h"

#include "IShaderByteCodeNative.h"
#include "IResourceCreateContextNative.h"

#include "shaders/default_compute_signature.h"


namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
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
    
    ComputePipelineState::ComputePipelineState(ResourceCreateContext const& ctx, ComputePipelineStateDescription const& d)
    {
        using namespace uc::gx::dx12;

        auto nativeCode = d.CS().as<IShaderByteCodeNative>();
        auto native     = ctx.as<IResourceCreateContextNative>();
        auto device     = native->GetDevice();
        auto r          = native->GetResourceCreateContext();
        
        m_cached_root_signature =                    create_default_compute_signature(device);

        {
            auto blob = default_compute_signature();
            m_cached_meta_data = parse_root_signature(blob.code(), blob.code_size(), r->null_cbv(), r->null_srv(), r->null_uav(), r->null_sampler());
        }

        {
            auto codeBlob = nativeCode->GetShaderByteCode();
            auto description = create_compute_pipeline_state_internal(m_cached_root_signature.Get(), &codeBlob);
            m_cached_pipeline_state = create_compute_pipeline_state(device, &description);
        }

        m_compute_pipeline_state = { m_cached_pipeline_state.Get(), m_cached_root_signature.Get(), &m_cached_meta_data };
    }

	uc::gx::dx12::compute_pipeline_state* ComputePipelineState::GetPipelineState()
	{
		return &m_compute_pipeline_state;
	}
}
