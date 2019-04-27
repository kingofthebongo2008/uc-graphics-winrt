#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include "UniqueCreator.Graphics.Gpu.FrameDepthStencilBuffer.g.h"
#include "UniqueCreator.Graphics.Gpu.ViewDepthStencilBuffer.g.h"
#include "IDepthBufferNative.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc::gx::dx12;

    struct FrameDepthStencilBuffer :  FrameDepthStencilBufferT<FrameDepthStencilBuffer, IGpuVirtualResourceNative, IDepthStencilBufferNative >
    {
        FrameDepthStencilBuffer(gpu_depth_stencil_buffer* b);

        void Dummy1() {}

        GpuVirtualAddress VirtualAddress() const;

		gpu_depth_stencil_buffer*   GetDepthStencilBuffer();
        gpu_virtual_resource*		GetResource();

        Size2D            Size2D() const;
        Size3D            Size3D() const;
        private:
        gpu_depth_stencil_buffer*  m_depth_buffer;
   };  

	struct ViewDepthStencilBuffer : FrameDepthStencilBufferT<ViewDepthStencilBuffer, IGpuVirtualResourceNative, IDepthStencilBufferNative >
	{
		ViewDepthStencilBuffer(gpu_depth_stencil_buffer* b);

		void Dummy1() {}

		GpuVirtualAddress VirtualAddress() const;

		gpu_depth_stencil_buffer* GetDepthStencilBuffer();
		gpu_virtual_resource* GetResource();

		Size2D            Size2D() const;
		Size3D            Size3D() const;
	private:
		gpu_depth_stencil_buffer* m_depth_buffer;
	};
}

