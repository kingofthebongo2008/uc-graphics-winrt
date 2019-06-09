#pragma once
#include <windows.foundation.h>

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics
{
    using namespace uc;
    struct derivatives_skinned_mesh
    {
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

        gpu_mesh                                            m_mesh;
        gpu_mesh_opaque                                     m_mesh_opaque;
        gx::dx12::managed_byteaddress_gpu_buffer            m_geometry;
    };

    struct __declspec(uuid("71282AAA-343A-4227-86BF-8402A3D52C5C")) __declspec(novtable) IDerivativesSkinnedModelNative : ::IUnknown
    {
        virtual derivatives_skinned_mesh* GetMesh() = 0;
    };
}
