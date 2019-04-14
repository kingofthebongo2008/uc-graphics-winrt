#include "pch.h"
#include "GraphicsPipelineState.h"


#include "IShaderByteCodeNative.h"
#include "IResourceCreateContextNative.h"

#include "shaders/default_compute_signature.h"


namespace winrt::UniqueCreator::Graphics::implementation
{
    namespace
    {
        static D3D12_SHADER_BYTECODE create_shader_byte_code(const Blob s)
        {
            D3D12_SHADER_BYTECODE r = {};

			if (!s.empty())
			{
				r.pShaderBytecode = s.m_code;
				r.BytecodeLength = s.m_code_size;
			}
            return r;
        }
    }
    
    GraphicsPipelineState::GraphicsPipelineState(ResourceCreateContext const& ctx, GraphicsPipelineStateDescription const& d)
    {
        using namespace uc::gx::dx12;

		winrt::com_ptr< IShaderByteCodeNative > vs;
		winrt::com_ptr< IShaderByteCodeNative > ps;
		winrt::com_ptr< IShaderByteCodeNative > ds;
		winrt::com_ptr< IShaderByteCodeNative > hs;
		winrt::com_ptr< IShaderByteCodeNative > gs;

		if (d.VS())
		{
			vs = d.VS().as<IShaderByteCodeNative>();
		}

		if (d.PS())
		{
			ps = d.PS().as<IShaderByteCodeNative>();
		}

		if (d.DS())
		{
			ds = d.DS().as<IShaderByteCodeNative>();
		}

		if (d.HS())
		{
			hs = d.HS().as<IShaderByteCodeNative>();
		}

		if (d.GS())
		{
			gs = d.GS().as<IShaderByteCodeNative>();
		}

		auto native     = ctx.as<IResourceCreateContextNative>();
        auto device     = native->GetDevice();
        auto r          = native->GetResourceCreateContext();
        
        m_cached_root_signature =                    create_default_graphics_signature(device);

		{
            auto blob = default_graphics_signature();
            m_cached_meta_data = parse_root_signature(blob.code(), blob.code_size(), r->null_cbv(), r->null_srv(), r->null_uav(), r->null_sampler());
        }

		/*
		typedef struct D3D12_GRAPHICS_PIPELINE_STATE_DESC
		{
			D3D12_STREAM_OUTPUT_DESC StreamOutput;
			D3D12_BLEND_DESC BlendState;
			D3D12_INPUT_LAYOUT_DESC InputLayout;
		} 	D3D12_GRAPHICS_PIPELINE_STATE_DESC;
		*/

        {
			D3D12_GRAPHICS_PIPELINE_STATE_DESC description = {};
			description.pRootSignature = m_cached_root_signature.Get();
			description.VS = create_shader_byte_code(vs->GetShaderByteCode());
			description.PS = create_shader_byte_code(ps->GetShaderByteCode());
			description.DS = create_shader_byte_code(ds->GetShaderByteCode());
			description.HS = create_shader_byte_code(hs->GetShaderByteCode());
			description.GS = create_shader_byte_code(gs->GetShaderByteCode());

			
			{
				description.RasterizerState.FillMode = static_cast<D3D12_FILL_MODE>(d.RasterizerState().FillMode);
				description.RasterizerState.CullMode = static_cast<D3D12_CULL_MODE>(d.RasterizerState().CullMode);
				description.RasterizerState.FrontCounterClockwise = d.RasterizerState().FrontCounterClockwise;
				description.RasterizerState.DepthBias = d.RasterizerState().DepthBias;

				description.RasterizerState.SlopeScaledDepthBias = d.RasterizerState().SlopeScaledDepthBias;
				description.RasterizerState.DepthClipEnable = d.RasterizerState().DepthClipEnable;
				description.RasterizerState.MultisampleEnable = d.RasterizerState().MultisampleEnable;
				description.RasterizerState.AntialiasedLineEnable = d.RasterizerState().AntialiasedLineEnable;
				description.RasterizerState.ForcedSampleCount = d.RasterizerState().ForcedSampleCount;

				description.RasterizerState.ConservativeRaster = static_cast<D3D12_CONSERVATIVE_RASTERIZATION_MODE>(d.RasterizerState().ConservativeRaster);
			}

			{
				description.DepthStencilState.DepthEnable		= d.DepthStencilState().DepthEnable;
				description.DepthStencilState.DepthWriteMask	= static_cast<D3D12_DEPTH_WRITE_MASK>(d.DepthStencilState().DepthWriteMask);
				description.DepthStencilState.DepthFunc			= static_cast<D3D12_COMPARISON_FUNC>(d.DepthStencilState().DepthFunc);
				description.DepthStencilState.StencilEnable		= static_cast<D3D12_COMPARISON_FUNC>(d.DepthStencilState().StencilEnable);
				description.DepthStencilState.StencilReadMask	= static_cast<UINT8>(d.DepthStencilState().StencilReadMask);
				description.DepthStencilState.StencilWriteMask	= static_cast<UINT8>(d.DepthStencilState().StencilWriteMask);

				description.DepthStencilState.FrontFace.StencilFailOp = static_cast<D3D12_STENCIL_OP>(d.DepthStencilState().FrontFace.StencilFailOperation);
				description.DepthStencilState.FrontFace.StencilDepthFailOp = static_cast<D3D12_STENCIL_OP>(d.DepthStencilState().FrontFace.StencilDepthFailOperation);
				description.DepthStencilState.FrontFace.StencilPassOp = static_cast<D3D12_STENCIL_OP>(d.DepthStencilState().FrontFace.StencilPassOperation);
				description.DepthStencilState.FrontFace.StencilFunc = static_cast<D3D12_COMPARISON_FUNC>(d.DepthStencilState().FrontFace.StencilFunction);

				description.DepthStencilState.BackFace.StencilFailOp = static_cast<D3D12_STENCIL_OP>(d.DepthStencilState().BackFace.StencilFailOperation);
				description.DepthStencilState.BackFace.StencilDepthFailOp = static_cast<D3D12_STENCIL_OP>(d.DepthStencilState().BackFace.StencilDepthFailOperation);
				description.DepthStencilState.BackFace.StencilPassOp = static_cast<D3D12_STENCIL_OP>(d.DepthStencilState().BackFace.StencilPassOperation);
				description.DepthStencilState.BackFace.StencilFunc = static_cast<D3D12_COMPARISON_FUNC>(d.DepthStencilState().BackFace.StencilFunction);
			}

			{
				description.PrimitiveTopologyType = static_cast<D3D12_PRIMITIVE_TOPOLOGY_TYPE> (d.PrimitiveTopology());
			}

			{
				auto&& targets = d.RtvFormats();
				auto i = 0;
				for (auto&& t : targets)
				{
					description.RTVFormats[i++] = static_cast<DXGI_FORMAT>(t);
				}
				description.NumRenderTargets = targets.Size();
			}

			{
				description.SampleMask	= d.SampleMask();
				description.DSVFormat	= static_cast<DXGI_FORMAT>(d.DsvFormat());

				description.SampleDesc.Count = d.Samples().Count;
				description.SampleDesc.Quality = d.Samples().Quality;
				description.IBStripCutValue = static_cast<D3D12_INDEX_BUFFER_STRIP_CUT_VALUE> (d.IbStripCutValue());
			}

			{
				auto view = d.InputLayout();
				
				if (view.InputElementDescs().Size() > 0)
				{
					std::vector<InputElementDescription> elements1;
					elements1.resize(view.InputElementDescs().Size());
					view.InputElementDescs().GetMany(0, array_view<InputElementDescription>(elements1));

					std::vector< D3D12_INPUT_ELEMENT_DESC > elements2;
					elements2.resize(elements1.size());

					uint32_t i = 0;
					for (auto&& e : elements1)
					{
						elements2[i].AlignedByteOffset		= e.AlignedByteOffset;
						elements2[i].Format					= static_cast<DXGI_FORMAT> (e.Format);
						elements2[i].InputSlot				= e.InputSlot;
						elements2[i].InputSlotClass			= static_cast<D3D12_INPUT_CLASSIFICATION> (e.InputSlotClass);
						elements2[i].InstanceDataStepRate	= e.InstanceDataStepRate;
						elements2[i].SemanticIndex			= e.SemanticIndex;
						//elements2[i].SemanticName			= e.SemanticName().c_str();
					}
				}
			}

            m_cached_pipeline_state = create_graphics_pipeline_state(device, &description);
        }

        m_graphics_pipeline_state = { m_cached_pipeline_state.Get(), m_cached_root_signature.Get(), &m_cached_meta_data };
    }

	uc::gx::dx12::graphics_pipeline_state* GraphicsPipelineState::GetPipelineState()
	{
		return &m_graphics_pipeline_state;
	}
}
