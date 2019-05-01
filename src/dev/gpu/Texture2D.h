#pragma once
#include "UniqueCreator.Graphics.Gpu.Texture2D.g.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
	using namespace uc::gx::dx12;

    struct Texture2D : Texture2DT<Texture2D, IGpuVirtualResourceNative >
    {
        Texture2D(managed_gpu_texture_2d g);

        GpuVirtualAddress VirtualAddress() const;

        Size2D Size2D() const;
        Size3D Size3D() const;

        CpuDescriptorHandle SRV() const;
        CpuDescriptorHandle UAV() const;

        void Dummy1();

		uc::gx::dx12::gpu_virtual_resource* GetResource();

		private:
		managed_gpu_texture_2d m_texture;
    };
}
