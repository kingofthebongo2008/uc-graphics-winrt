#include "pch.h"
#include "winrt.h"

#include "UniqueCreator.Graphics.Gpu.GraphicsPipelineState.h"

#include "IShaderByteCodeNative.h"
#include "IResourceCreateContextNative.h"

#include <default_compute_signature.h>
#include <uc/util/utf8_conv.h>


namespace winrt::UniqueCreator::Graphics::Gpu::implementation
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
    
    GraphicsPipelineState::GraphicsPipelineState(ResourceCreateContext const& ctx, GraphicsPipelineStateDescription const& d0)
    {
		GraphicsPipelineStateDescription const d = d0;
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

        {
			D3D12_GRAPHICS_PIPELINE_STATE_DESC description = {};
			description.pRootSignature = m_cached_root_signature.Get();
			description.VS = create_shader_byte_code(vs->GetShaderByteCode());
			description.PS = create_shader_byte_code(ps->GetShaderByteCode());
			description.DS = create_shader_byte_code(ds->GetShaderByteCode());
			description.HS = create_shader_byte_code(hs->GetShaderByteCode());
			description.GS = create_shader_byte_code(gs->GetShaderByteCode());

			//Rasterizer state
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

			//Depth Stencil State
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

			//Rtv Formats
			{
				auto&& targets = d.RtvFormats();
				auto i = 0;
				for (auto&& t : targets)
				{
					description.RTVFormats[i++] = static_cast<DXGI_FORMAT>(t);
				}
				description.NumRenderTargets = targets.Size();
			}
			//Dsv Sample
			{
				description.SampleMask	= d.SampleMask();
				description.DSVFormat	= static_cast<DXGI_FORMAT>(d.DsvFormat());

				description.SampleDesc.Count = d.Samples().Count;
				description.SampleDesc.Quality = d.Samples().Quality;
				description.IBStripCutValue = static_cast<D3D12_INDEX_BUFFER_STRIP_CUT_VALUE> (d.IbStripCutValue());
			}

			std::vector< D3D12_INPUT_ELEMENT_DESC > ia;
			std::vector< std::string >				ia_strings;
			
			//Input Description
			{
				auto&& view = d.InputLayout();
				
				if (view && view.InputElementDescs().Size() > 0)
				{
					std::vector<InputElementDescription> elements1;
					elements1.resize(view.InputElementDescs().Size());
					view.InputElementDescs().GetMany(0, array_view<InputElementDescription>(elements1));

					ia.resize(elements1.size());
					ia_strings.resize(elements1.size());

					uint32_t i = 0;
					for (auto&& e : elements1)
					{
						ia_strings[i]				= uc::util::utf8_from_utf16(e.SemanticName.c_str());
						ia[i].AlignedByteOffset		= e.AlignedByteOffset;
						ia[i].Format				= static_cast<DXGI_FORMAT> (e.Format);
						ia[i].InputSlot				= e.InputSlot;
						ia[i].InputSlotClass		= static_cast<D3D12_INPUT_CLASSIFICATION> (e.InputSlotClass);
						ia[i].InstanceDataStepRate	= e.InstanceDataStepRate;
						ia[i].SemanticIndex			= e.SemanticIndex;
						ia[i].SemanticName			= ia_strings[i].c_str();
					}

					description.InputLayout.NumElements = static_cast<uint32_t> (ia.size());
					description.InputLayout.pInputElementDescs = &ia[0];
				}
			}

			std::vector< D3D12_SO_DECLARATION_ENTRY > so;
			std::vector< std::string >				  so_strings;
			std::vector< std::uint32_t >			  so_strides;

			//Stream out
			{
				auto&& so_ = d.StreamOutput();

				if (so_ && so_.SODeclaration().Size() > 0)
				{
					std::vector<StreamOutputDeclarationEntry> elements1;
					elements1.resize(so_.SODeclaration().Size());
					so_.SODeclaration().GetMany(0, array_view<StreamOutputDeclarationEntry>(elements1));

					so_strings.resize(elements1.size());
					so.resize(elements1.size());

					uint32_t i = 0;
					for (auto&& e : elements1)
					{
						so_strings[i] = uc::util::utf8_from_utf16(e.SemanticName.c_str());
						so[i].ComponentCount = e.ComponentCount;
						so[i].SemanticIndex = e.SemanticIndex;
						so[i].SemanticName = so_strings[i].c_str();
						so[i].OutputSlot = e.OutputSlot;
						so[i].StartComponent = e.StartComponent;
						so[i].Stream = e.Stream;
					}


					description.StreamOutput.RasterizedStream = so_.RasterizedStream();
					description.StreamOutput.pSODeclaration = &so[0];
					description.StreamOutput.NumEntries = static_cast<uint32_t> (so.size());
				}

				if (so_.BufferStrides().Size() > 0)
				{
					so_strides.resize(so_.BufferStrides().Size());
					so_.BufferStrides().GetMany(0, array_view<uint32_t>(so_strides));

					description.StreamOutput.pBufferStrides = &so_strides[0];
					description.StreamOutput.NumStrides = static_cast<uint32_t> (so_strides.size());
				}

			}


			description.BlendState.AlphaToCoverageEnable = d.BlendState().AlphaToCoverageEnable();
			description.BlendState.IndependentBlendEnable = d.BlendState().IndependentBlendEnable();

			//Blend state
			{
				if (d.BlendState() && d.BlendState().RenderTargets().Size() > 0)
				{
					std::vector<RenderTargetBlendDescription> blends;
					blends.resize(d.BlendState().RenderTargets().Size());
					d.BlendState().RenderTargets().GetMany(0, array_view<RenderTargetBlendDescription>(blends));

					uint32_t i = 0;
					for (auto& v : blends)
					{
						description.BlendState.RenderTarget[i].BlendEnable = v.BlendEnable;
						description.BlendState.RenderTarget[i].LogicOpEnable = v.LogicOperationEnable;

						description.BlendState.RenderTarget[i].SrcBlend = static_cast<D3D12_BLEND> (v.SourceBlend);
						description.BlendState.RenderTarget[i].DestBlend = static_cast<D3D12_BLEND> (v.DestinationBlend);
						description.BlendState.RenderTarget[i].BlendOp = static_cast<D3D12_BLEND_OP> (v.BlendOperation);

						description.BlendState.RenderTarget[i].SrcBlendAlpha = static_cast<D3D12_BLEND> (v.SourceBlendAlpha);
						description.BlendState.RenderTarget[i].DestBlendAlpha = static_cast<D3D12_BLEND> (v.DestinationBlendAlpha);
						description.BlendState.RenderTarget[i].BlendOpAlpha = static_cast<D3D12_BLEND_OP> (v.BlendOperationAlpha);

						description.BlendState.RenderTarget[i].LogicOp = static_cast<D3D12_LOGIC_OP> (v.LogicOperation);
						description.BlendState.RenderTarget[i].RenderTargetWriteMask = static_cast<D3D12_LOGIC_OP> (v.RenderTargetWriteMask);
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
