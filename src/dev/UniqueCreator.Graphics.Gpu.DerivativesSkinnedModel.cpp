#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModel.h"

#include "IResourceCreateContextNative.h"
#include "IGraphicsComputeCommandContextNative.h"
#include "cmd/GraphicsComputeCommandContext.h"

#define UWP
#include <uc/gx/lip/lip.h>
#include <uc/gx/lip_utils.h>
#include <uc/gx/dx12/dx12.h>
#include <shaders/interop.h>

#include "file.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace uc;

	namespace
	{
		size_t align(size_t v, size_t a)
		{
			return (v + a - 1) & (~(a - 1));
		}
	}

	DerivativesSkinnedModel::DerivativesSkinnedModel(UniqueCreator::Graphics::Gpu::DerivativesSkinnedMaterial const& m, UniqueCreator::Graphics::Gpu::ResourceCreateContext const& _rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& _c, hstring const& _payload) :
    m_material(m)
    {
        auto mesh		= lip::create_from_compressed_lip_file<lip::derivatives_skinned_model>(_payload.c_str());
		auto pos		= static_cast<uint32_t>(align(size(mesh->m_positions), 256U));
		auto uv			= static_cast<uint32_t>(align(size(mesh->m_uv), 256U));
		auto normals	= static_cast<uint32_t>(align(size(mesh->m_normals), 256UL));
		auto tangents	= static_cast<uint32_t>(align(size(mesh->m_tangents), 256UL));
		auto indices	= static_cast<uint32_t>(align(size(mesh->m_indices), 256UL));

		auto native		= _rc.as<IResourceCreateContextNative>();
		auto rc			= native->GetResourceCreateContext();
		auto ctx		= _c.as< IGraphicsComputeCommandContextNative >()->GetContext();

        m_mesh.m_mesh_opaque.m_opaque_textures.resize(mesh->m_textures.size());
        m_mesh.m_mesh_opaque.m_opaque_ranges.resize(mesh->m_primitive_ranges.size());

		for (auto i = 0U; i < mesh->m_textures.size(); ++i)
		{
			const auto& texture = mesh->m_textures[i];

			auto w = texture.m_levels[0].m_width;
			auto h = texture.m_levels[0].m_height;

            m_mesh.m_mesh_opaque.m_opaque_textures[i] = gx::dx12::create_texture_2d(rc, w, h, static_cast<DXGI_FORMAT>(texture.m_levels[0].view()), D3D12_RESOURCE_STATE_COPY_DEST);
			D3D12_SUBRESOURCE_DATA s[1];
			s[0] = gx::sub_resource_data(&texture.m_levels[0]);
			ctx->upload_resource(m_mesh.m_mesh_opaque.m_opaque_textures[i].get(), 0, 1, &s[0]);
		}

		for (auto i = 0U; i < mesh->m_primitive_ranges.size(); ++i)
		{
			const auto& r = mesh->m_primitive_ranges[i];
            m_mesh.m_mesh_opaque.m_opaque_ranges[i].m_begin = r.m_begin;
            m_mesh.m_mesh_opaque.m_opaque_ranges[i].m_end = r.m_end;
		}

		auto s		= static_cast<uint32_t> (pos + uv + normals + tangents + indices);
        m_mesh.m_geometry	= gx::dx12::create_byteaddress_buffer(rc, s, D3D12_RESOURCE_STATE_COPY_DEST);

		//allocation
        m_mesh.m_mesh.m_pos = 0;
        m_mesh.m_mesh.m_uv = pos;
        m_mesh.m_mesh.m_normals = pos + uv;
        m_mesh.m_mesh.m_tangents = pos + uv + normals;
        m_mesh.m_mesh.m_indices = pos + uv + normals + tangents;
        m_mesh.m_mesh.m_indices_size = static_cast<uint32_t>(size(mesh->m_indices));
        m_mesh.m_mesh.m_vertex_count = static_cast<uint32_t>(mesh->m_positions.size());

		ctx->upload_buffer(m_mesh.m_geometry.get(), m_mesh.m_mesh.m_pos, mesh->m_positions.data(), size(mesh->m_positions));
		ctx->upload_buffer(m_mesh.m_geometry.get(), m_mesh.m_mesh.m_uv, mesh->m_uv.data(), size(mesh->m_uv));
		ctx->upload_buffer(m_mesh.m_geometry.get(), m_mesh.m_mesh.m_normals, mesh->m_normals.data(), size(mesh->m_normals));
		ctx->upload_buffer(m_mesh.m_geometry.get(), m_mesh.m_mesh.m_tangents, mesh->m_tangents.data(), size(mesh->m_tangents));
		ctx->upload_buffer(m_mesh.m_geometry.get(), m_mesh.m_mesh.m_indices, mesh->m_indices.data(), size(mesh->m_indices));

		ctx->transition_resource(m_mesh.m_geometry.get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE);

		for (auto&& t : m_mesh.m_mesh_opaque.m_opaque_textures)
		{
			ctx->transition_resource(t.get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
		}
    }

    derivatives_skinned_mesh* DerivativesSkinnedModel::GetMesh() 
    {
        return &m_mesh;
    }

    void DerivativesSkinnedModel::SubmitDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        graphics->set_graphics_root_constant(0, 1, offsetof(interop::draw_call, m_batch) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, 0, offsetof(interop::draw_call, m_start_vertex) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_pos, offsetof(interop::draw_call, m_position) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_uv, offsetof(interop::draw_call, m_uv) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_normals, offsetof(interop::draw_call, m_normal) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_tangents, offsetof(interop::draw_call, m_tangent) / sizeof(uint32_t));

        graphics->set_graphics_srv_buffer(2, m_mesh.m_geometry.get());
        graphics->set_primitive_topology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        graphics->set_index_buffer({ m_mesh.m_geometry->virtual_address() + m_mesh.m_mesh.m_indices, m_mesh.m_mesh.m_indices_size, DXGI_FORMAT_R32_UINT });
    }

    void DerivativesSkinnedModel::SubmitAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d)
    {
        auto graphics = d.as< IGraphicsComputeCommandContextNative >()->GetContext();

        graphics->set_graphics_root_constant(0, 1, offsetof(interop::draw_call, m_batch) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, 0, offsetof(interop::draw_call, m_start_vertex) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_pos, offsetof(interop::draw_call, m_position) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_uv, offsetof(interop::draw_call, m_uv) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_normals, offsetof(interop::draw_call, m_normal) / sizeof(uint32_t));
        graphics->set_graphics_root_constant(0, m_mesh.m_mesh.m_tangents, offsetof(interop::draw_call, m_tangent) / sizeof(uint32_t));

        graphics->set_graphics_srv_buffer(2, m_mesh.m_geometry.get());
        graphics->set_primitive_topology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        graphics->set_index_buffer({ m_mesh.m_geometry->virtual_address() + m_mesh.m_mesh.m_indices, m_mesh.m_mesh.m_indices_size, DXGI_FORMAT_R32_UINT });
    }
}

