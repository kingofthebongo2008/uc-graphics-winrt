#include "default_signature.hlsli"

struct interpolated_value
{
	float4 m_position : SV_POSITION;
    float3 m_color    : TEXCOORD0;
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

	return r;
}