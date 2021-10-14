#pragma once
#include "Actor/DsActorInfo_Base.h"
#include "Actor/Ue/DsUePawn.h"
#include "DsActorInfo_Visible.generated.h"


USTRUCT()
struct FDsActorInfo_Visible : public FDsActorInfo_Base
{
	GENERATED_BODY()

public:
	FDsActorInfo_Visible() {}
	FDsActorInfo_Visible(const FName& ActorTid, const FVector& vPos, const float fAngle)
		: m_ActorTid(ActorTid), m_vPos(vPos), m_fAngle(fAngle) {}

	TWeakObjectPtr<ADsUePawn> m_wpUeActor;
	FName m_ActorTid;
	FVector m_vPos;
	float m_fAngle;
};