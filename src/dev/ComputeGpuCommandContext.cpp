#include "pch.h"
#include "ComputeGpuCommandContext.h"

#include "FenceHandle.h"

#include "IGpuVirtualResourceNative.h"
#include "IBackBufferNative.h"
#include "IComputePipelineStateNative.h"

namespace winrt::UniqueCreator::Graphics::implementation
{
    ComputeGpuCommandContext::ComputeGpuCommandContext(uc::gx::dx12::managed_compute_command_context ctx) : m_ctx(std::move(ctx))
    {

    }

	IFenceHandle ComputeGpuCommandContext::Submit()
    {
        auto r = make<FenceHandle>(m_ctx->submit(uc::gx::dx12::gpu_command_context::do_not_wait_to_execute));
        m_ctx.reset();
        return r;
    }

    void ComputeGpuCommandContext::SubmitAndWaitToExecute()
    {
        m_ctx->submit(uc::gx::dx12::gpu_command_context::wait_to_execute);
        m_ctx.reset();
    }

    void ComputeGpuCommandContext::TransitionResource(IGpuVirtualResource r, ResourceState old_state, ResourceState new_state)
    {
        com_ptr<IGpuVirtualResourceNative> r0(r.as<IGpuVirtualResourceNative>());

        m_ctx->transition_resource(r0->GetResource(), static_cast<D3D12_RESOURCE_STATES>(old_state), static_cast<D3D12_RESOURCE_STATES>(new_state));
    }

    void ComputeGpuCommandContext::Dispatch(uint32_t x, uint32_t y, uint32_t z)
    {
		m_ctx->dispatch(x, y, z);
    }

	void ComputeGpuCommandContext::SetPSO(const ComputePipelineState& s)
    {
		auto native = s.as<IComputePipelineStateNative>();
		m_ctx->set_pso(native->GetPipelineState());
    }

	void ComputeGpuCommandContext::SetComputeUAVBuffer(uint32_t slot, IGpuVirtualResource r)
	{
		com_ptr<IGpuVirtualResourceNative> r0(r.as<IGpuVirtualResourceNative>());
		m_ctx->set_compute_uav_buffer(slot, r0->GetResource());
	}
}
