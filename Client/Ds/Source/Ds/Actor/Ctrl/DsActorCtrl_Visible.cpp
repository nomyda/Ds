#include "DsActorCtrl_Visible.h"
#include "Mgr/FrameWork/DsFrameWorkMgr.h"

FDsActorCtrl_Visible::FDsActorCtrl_Visible() 
	: FDsActorCtrl_Base()
{
}

void FDsActorCtrl_Visible::InitCtrl(DsActor* pParentActor)
{
	Super::InitCtrl(pParentActor);
	UWorld* pWorld = DsFrameWorkMgr::Get().GetWorld();
	if (nullptr == pWorld)
		return;

	FActorSpawnParameters _Param;
/*	_Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FRotator _Rot(0.0f, Info.m_fAngle, 0.0f);
	ADSPawn* pPawn = pWorld->SpawnActor<ADSPawn>(Info.m_vPos, _Rot, _Param);*/	
}