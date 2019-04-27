#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include "UniqueCreator.Graphics.Gpu.FrameDepthBuffer.g.h"
#include "UniqueCreator.Graphics.Gpu.ViewDepthBuffer.g.h"
#include "IDepthBufferNative.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc::gx::dx12;

    struct FrameDepthBuffer :  FrameDepthBufferT<FrameDepthBuffer, IGpuVirtualResourceNative, IDepthBufferNative >
    {
        FrameDepthBuffer(gpu_depth_buffer* b);

        void Dummy1() {}

        GpuVirtualAddress VirtualAddress() const;

        gpu_depth_buffer*       GetDepthBuffer();
        gpu_virtual_resource*   GetResource();

        Size2D            Size2D() const;
        Size3D            Size3D() const;
        private:
        gpu_depth_buffer*  m_depth_buffer;
   };  

	struct ViewDepthBuffer : ViewDepthBufferT<ViewDepthBuffer, IGpuVirtualResourceNative, IDepthBufferNative >
	{
		ViewDepthBuffer(gpu_depth_buffer* b);

		void Dummy1() {}

		GpuVirtualAddress VirtualAddress() const;

		gpu_depth_buffer* GetDepthBuffer();
		gpu_virtual_resource* GetResource();

		Size2D            Size2D() const;
		Size3D            Size3D() const;
		private:
		gpu_depth_buffer* m_depth_buffer;
	};
}

