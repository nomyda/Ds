#include "DsActorCtrl_Visible.h"
#include "Mgr/FrameWork/DsFrameWorkMgr.h"
#include "Actor/Info/DsActorInfo_Visible.h"
#include "Actor/DsActor.h"
#include "Actor/Ue/DsUePawn.h"

FDsActorCtrl_Visible::FDsActorCtrl_Visible() 
	: FDsActorCtrl_Base()
{
}

void FDsActorCtrl_Visible::InitCtrl(DsActor* pParentActor)
{
	Super::InitCtrl(pParentActor);
	FDsActorInfo_Visible* pVisibleInfo = pParentActor->GetChild<FDsActorInfo_Visible>();
	if (nullptr == pVisibleInfo)
		return;

	UWorld* pWorld = DsFrameWorkMgr::Get().GetWorld();
	if (nullptr == pWorld)
		return;
	
	FActorSpawnParameters _Param;
	_Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FRotator _Rot(0.0f, pVisibleInfo->m_fAngle, 0.0f);
	pVisibleInfo->m_wpUeActor = pWorld->SpawnActor<ADsUePawn>(pVisibleInfo->m_vPos, _Rot, _Param);
	pVisibleInfo->m_wpUeActor->m_ActorTid = pVisibleInfo->m_ActorTid;
}