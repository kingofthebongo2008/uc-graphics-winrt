#include "pch.h"
#include "ComputePipelineStateDescription.h"

namespace winrt::UniqueCreator::Graphics::implementation
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
