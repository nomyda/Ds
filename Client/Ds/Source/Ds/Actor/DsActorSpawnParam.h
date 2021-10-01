#pragma once

struct FDsActorSpawnParam
{
public:
	FDsActorSpawnParam(const FVector& vPos, const float fAngle)
		: m_vPos(vPos)
		, m_fAngle(fAngle)
	{

	}

	FVector m_vPos;
	float m_fAngle;
};