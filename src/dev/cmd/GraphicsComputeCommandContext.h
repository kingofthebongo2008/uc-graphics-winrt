﻿#pragma once

#include "winrt/UniqueCreator.Graphics.Gpu.h"

#include <uc/gx/dx12/dx12.h>

#include "../IGraphicsComputeCommandContextNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    struct DirectGpuCommandContext : implements<DirectGpuCommandContext, IGraphicsComputeCommandContext, IComputeCommandContext, ICommandContext, IGraphicsComputeCommandContextNative >
    {
        DirectGpuCommandContext(uc::gx::dx12::managed_graphics_compute_command_context ctx);

        IFenceHandle Submit();
        void SubmitAndWaitToExecute();
        void TransitionResource(const IVirtualResource& r, ResourceState old_state, ResourceState new_state);
        void CopyResource(const IVirtualResource& d, const IVirtualResource& s);

        void Draw(uint32_t vertex_count, uint32_t vertex_offset);
        void DrawInstanced(uint32_t vertexCountPerInstance, uint32_t instanceCount, uint32_t startVertexLocation, uint32_t startInstanceLocation);
        void DrawIndexed(uint32_t indexCount, uint32_t startIndexLocation, int32_t baseVertexLocation);
        void DrawIndexedInstanced(uint32_t indexCountPerInstance, uint32_t instanceCount, uint32_t startIndexLocation, int32_t baseVertexLocation, uint32_t startInstanceLocation);

        void SetDescriptorHeaps();
        
        void SetGraphicsPipelineStateObject(const GraphicsPipelineState& s);

        void SetViewPort(const ViewPort& vp);
        void SetScissorRectangle(const Rectangle2D& r);
        void SetPrimitiveTopology(const PrimitiveTopology& t);

        void SetIndexBuffer(const IndexBufferView& view);
        void SetVertexBuffer(uint32_t slot, const VertexBufferView& view);

        void Clear(const SwapChainBuffer& b);
        void Clear(const IColorBuffer& b);
        void Clear(const IDepthBuffer& b);
        void Clear(const IDepthStencilBuffer& b);

        void SetRenderTargetSimple(const IColorBuffer& b);
        void SetRenderTargetSimple(const SwapChainBuffer& b);
        void SetRenderTargetSimple(const IDepthBuffer& d);
        void SetRenderTargetSimple(const IDepthStencilBuffer& d);

        void SetRenderTarget(const IColorBuffer& b, const IDepthBuffer& d);
        void SetRenderTarget(const IColorBuffer& b, const IDepthStencilBuffer& d);
        void SetRenderTarget(const SwapChainBuffer& b, const IDepthBuffer& d);
        void SetRenderTarget(const SwapChainBuffer& b, const IDepthStencilBuffer& d);

        void SetGraphicsSRVBuffer(uint32_t rootIndex, const IVirtualResource& r);
        void SetGraphicsUAVBuffer(uint32_t rootIndex, const IVirtualResource& r);
        void SetGraphicsConstantBuffer(uint32_t rootIndex, GpuVirtualAddress r);

        void SetGraphicsSRV(uint32_t rootIndex, uint32_t offset, const IShaderResourceView& r);
        void SetGraphicsUAV(uint32_t rootIndex, uint32_t offset, const IUnorderedAccessView& r);
        void SetGraphicsRootConstant(uint32_t rootIndex, uint32_t offset, uint32_t constant);

        void SetGraphicsConstantBufferData(uint32_t rootIndex, const Windows::Foundation::Collections::IVector<uint8_t>& buffer);

        //Compute
        void SetComputePipelineStateObject(const ComputePipelineState& s);
        void Dispatch(uint32_t x, uint32_t y, uint32_t z);
        void SetComputeSRVBuffer(uint32_t rootIndex, const IVirtualResource& r);
        void SetComputeUAVBuffer(uint32_t rootIndex, const IVirtualResource& r);
        void SetComputeConstantBuffer(uint32_t rootIndex, const GpuVirtualAddress r);

        void SetComputeConstantBufferData(uint32_t rootIndex, const Windows::Foundation::Collections::IVector<uint8_t>& buffer);
        void SetComputeSRV(uint32_t rootIndex, uint32_t offset, const IShaderResourceView& r);
        void SetComputeUAV(uint32_t rootIndex, uint32_t offset, const IUnorderedAccessView& r);
        void SetComputeRootConstant(uint32_t rootIndex, uint32_t offset, uint32_t constant);

        void UpdateBuffer(const IVirtualResource& destination, uint32_t destination_offset, const Windows::Foundation::Collections::IVector<uint8_t>& buffer);
        void UploadResource(const IVirtualResource& r, uint32_t first_sub_resource, uint32_t sub_resource_count, const Windows::Foundation::Collections::IVector<Gpu::SubresourceData>& d);

        uc::gx::dx12::gpu_graphics_compute_command_context* GetContext();

        private:
        uc::gx::dx12::managed_graphics_compute_command_context m_ctx;
   };  
}

