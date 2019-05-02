#include "default_signature.hlsli"

struct interpolated_value
{
	float4 m_position : SV_POSITION;
    float3 m_color    : TEXCOORD0;
	float2 m_uv		  : TEXCOORD1;
};

ByteAddressBuffer b : register(t1);

[RootSignature( MyRS1 ) ]
interpolated_value main(uint v : SV_VERTEXID)
{
	interpolated_value r = (interpolated_value)0;

	uint positionStride = 16;
	uint colorStride	= 12;
	uint positionOffset = 0;
	uint colorOffset	= 16 * 3;

	r.m_position = asfloat(b.Load4(positionOffset + v * positionStride ));
	r.m_color	 = asfloat(b.Load3(colorOffset    + v * colorStride));
	r.m_uv = 0;

	if (v == 0)
	{
		r.m_uv = 0.0;
	}

	if (v == 1)
	{
		r.m_uv = float2(1.0, 0.0);
	}

	if (v == 2)
	{
		r.m_uv = float2(0.0, 1.0);
	}

	return r;
}