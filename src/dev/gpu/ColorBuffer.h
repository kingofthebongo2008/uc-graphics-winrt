#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"
#include "UniqueCreator.Graphics.Gpu.FrameColorBuffer.g.h"
#include "UniqueCreator.Graphics.Gpu.ViewColorBuffer.g.h"
#include "IBackBufferNative.h"
#include "IGpuVirtualResourceNative.h"

#include <uc/gx/dx12/dx12.h>

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    using namespace uc::gx::dx12;

    struct FrameColorBuffer : FrameColorBufferT<FrameColorBuffer, IGpuVirtualResourceNative, IColorBufferNative >
    {
		FrameColorBuffer(managed_gpu_frame_color_buffer b);


        void Dummy1() {}

        GpuVirtualAddress VirtualAddress() const;
		CpuDescriptorHandle SRV() const;
		CpuDescriptorHandle UAV() const;

        gpu_color_buffer*        GetColorBuffer();
        gpu_virtual_resource*    GetResource();


        Size2D            Size2D() const;
        Size3D            Size3D() const;
        private:
		managed_gpu_frame_color_buffer	     m_color_buffer;
   };  

	struct ViewColorBuffer : ViewColorBufferT<ViewColorBuffer, IGpuVirtualResourceNative, IColorBufferNative >
	{
		ViewColorBuffer(std::unique_ptr<gpu_view_color_buffer> b);

		void Dummy1() {}

		GpuVirtualAddress VirtualAddress() const;
		CpuDescriptorHandle SRV() const;
		CpuDescriptorHandle UAV() const;

		gpu_color_buffer* GetColorBuffer();
		gpu_virtual_resource* GetResource();

		Size2D            Size2D() const;
		Size3D            Size3D() const;
	private:
		std::unique_ptr<gpu_view_color_buffer>		m_color_buffer;
	};
}

