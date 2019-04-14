#pragma once
#include <windows.foundation.h>
#include <d3d12.h>

namespace winrt::UniqueCreator::Graphics
{
    struct Blob
    {
		const void* m_code		= nullptr;
		uint64_t    m_code_size = 0;;

		bool empty() const { return m_code == nullptr; }
    };

    struct __declspec(uuid("FFC87799-3211-44D7-96BC-609D7377D210")) __declspec(novtable) IShaderByteCodeNative : ::IUnknown
    {
        virtual Blob GetShaderByteCode() = 0;
    };
}
