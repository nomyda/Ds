#include "DSActorM.h"
//#include "GameFrameWork/Actor/DSActorInterface.h"
//#include "Info/DSActor_SpawnInfo.h"
//#include "Manager/GameFrameWork/DSGameFrameWorkM.h"
//#include "GameFrameWork/Actor/DSPawn.h"
//
//namespace Manager
//{
//	Def::EManager_Index DSActorM::GetIndex() const
//	{
//		return Def::EManager_Index::Actor;
//	}
//
//	IDSActorInterface* DSActorM::Appear(const FDSActor_SpawnInfo& Info)
//	{
//		UWorld* pWorld = DSGameFrameWorkM::GetM().GetWorld();
//		if (nullptr == pWorld)
//			return nullptr;
//
//		FActorSpawnParameters _Param;
//		_Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//		FRotator _Rot(0.0f, Info.m_fAngle, 0.0f);
//		ADSPawn* pPawn = pWorld->SpawnActor<ADSPawn>(Info.m_vPos, _Rot, _Param);
//		return pPawn;
//	}
//
//	bool DSActorM::Destroy(const int32 ActorID)
//	{
//		return false;
//	}
//}