#include "pch.h"
#include "ComputeCommandContext.h"

#include "UniqueCreator.Graphics.Gpu.FenceHandle.h"

#include "IGpuVirtualResourceNative.h"
#include "IBackBufferNative.h"
#include "IComputePipelineStateNative.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    ComputeCommandContext::ComputeCommandContext(uc::gx::dx12::managed_compute_command_context ctx) : m_ctx(std::move(ctx))
    {

    }

    IFenceHandle ComputeCommandContext::Submit()
    {
        auto r = make<FenceHandle>(m_ctx->submit(uc::gx::dx12::gpu_command_context::do_not_wait_to_execute));
        m_ctx.reset();
        return r;
    }

    void ComputeCommandContext::SubmitAndWaitToExecute()
    {
        m_ctx->submit(uc::gx::dx12::gpu_command_context::wait_to_execute);
        m_ctx.reset();
    }

    void ComputeCommandContext::TransitionResource(IVirtualResource r, ResourceState old_state, ResourceState new_state)
    {
        com_ptr<IGpuVirtualResourceNative> r0(r.as<IGpuVirtualResourceNative>());

        m_ctx->transition_resource(r0->GetResource(), static_cast<D3D12_RESOURCE_STATES>(old_state), static_cast<D3D12_RESOURCE_STATES>(new_state));
    }

    void ComputeCommandContext::Dispatch(uint32_t x, uint32_t y, uint32_t z)
    {
        m_ctx->dispatch(x, y, z);
    }

    void ComputeCommandContext::SetComputePipelineStateObject(const ComputePipelineState& s)
    {
        auto native = s.as<IComputePipelineStateNative>();
        m_ctx->set_pso(native->GetPipelineState());
    }

    void ComputeCommandContext::SetComputeUAVBuffer(uint32_t slot, IVirtualResource r)
    {
        com_ptr<IGpuVirtualResourceNative> r0(r.as<IGpuVirtualResourceNative>());
        m_ctx->set_compute_uav_buffer(slot, r0->GetResource());
    }

	void ComputeCommandContext::SetDescriptorHeaps()
	{
		m_ctx->set_descriptor_heaps();
	}
	
}
