#pragma once
//#include "Manager/DSBaseMgr.h"
//
//class DSActor;
//
//namespace Manager
//{
//	class DSMgrActor : public DSBaseMgr<DSMgrActor>
//	{
//	public:
//		DSMgrActor();
//
//		bool Init() override;
//		bool Release() override;
//
//		typedef TSharedPtr<DSActor> SharedActor;
//		SharedActor NewActor(const FName& ActorTid, const FVector& vPos, const float fAngle);
//
//	private:
//		uint32 NextGuid();
//
//	private:
//		TSortedMap<uint32, SharedActor> m_UniqueAndActor;
//		uint32 m_uNextGuid;
//	};
//}