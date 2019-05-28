#pragma once
#include "UniqueCreator.Graphics.Gpu.DerivativesSkinnedModel.g.h"


#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace uc;

    struct DerivativesSkinnedModel : DerivativesSkinnedModelT<DerivativesSkinnedModel>
    {
        DerivativesSkinnedModel() = default;

        DerivativesSkinnedModel(UniqueCreator::Graphics::Gpu::ResourceCreateContext const& rc, UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& ctx, hstring const& payload);
        UniqueCreator::Graphics::Gpu::DerivativesSkinnedModelInstance MakeInstance(UniqueCreator::Graphics::Gpu::Matrix44 const& d);
        void BeginDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void EndDepth(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void BeginAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);
        void EndAlbedo(UniqueCreator::Graphics::Gpu::IGraphicsComputeCommandContext const& d);


		private:

			struct gpu_mesh
			{
				uint32_t     m_pos;
				uint32_t     m_uv;
				uint32_t     m_normals;
				uint32_t     m_tangents;
				uint32_t     m_indices;
				uint32_t     m_indices_size;
				uint32_t     m_vertex_count;
			};

			struct gpu_primitive_range
			{
				uint32_t m_begin;
				uint32_t m_end;

				uint32_t index_count() const { return m_end - m_begin; }
			};

			struct gpu_mesh_opaque
			{
				std::vector<gx::dx12::managed_gpu_texture_2d>   m_opaque_textures;
				std::vector< gpu_primitive_range >              m_opaque_ranges;
			};

			gpu_mesh                                    m_mesh;
			gpu_mesh_opaque                             m_mesh_opaque;
			gx::dx12::managed_byteaddress_gpu_buffer	m_geometry;
    };
}
namespace winrt::UniqueCreator::Graphics::Gpu::factory_implementation
{
    struct DerivativesSkinnedModel : DerivativesSkinnedModelT<DerivativesSkinnedModel, implementation::DerivativesSkinnedModel>
    {
    };
}
