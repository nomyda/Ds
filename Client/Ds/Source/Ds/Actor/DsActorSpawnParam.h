#pragma once

struct FDsActorSpawnParam
{
public:
	FDsActorSpawnParam(const FName& Tid, const FVector& vPos, const float fAngle)
		: m_ActorTid(Tid)
		, m_vPos(vPos)
		, m_fAngle(fAngle)
	{

	}

	const FName m_ActorTid;
	const FVector m_vPos;
	const float m_fAngle;
};