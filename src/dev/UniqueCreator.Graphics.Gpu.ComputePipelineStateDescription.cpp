#include "pch.h"
#include "winrt.h"
#include "UniqueCreator.Graphics.Gpu.ComputePipelineStateDescription.h"

namespace winrt::UniqueCreator::Graphics::Gpu::implementation
{
    ComputeShaderByteCode ComputePipelineStateDescription::CS()
    {
		return m_code;
    }

    void ComputePipelineStateDescription::CS(ComputeShaderByteCode const& value)
    {
		m_code = value;
    }
}
