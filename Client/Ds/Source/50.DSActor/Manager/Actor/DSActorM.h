#pragma once
//#include "Manager/DSBaseMgr.h"
//
//class IDSActorInterface;
//
//namespace Manager
//{
//	class DSACTOR_API DSActorM : public DSBaseMgr<DSActorM>
//	{
//	public:
//		Def::EManager_Index GetIndex() const override;
//		IDSActorInterface* Create(const FDSActor_SpawnInfo& Info);
//		bool Destroy(const int32 ActorID);
//
//	protected:
//		// IManager
//		bool Init() override { return false; };
//		bool Release() override { return false; };
//	};
//}