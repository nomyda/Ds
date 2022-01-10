#include "DSMgrActor.h"
//#include "Actor/DSActor.h"
//#include "Manager/ClientVariable/DSClientVariableMgr.h"
//
//void NewActorConsolFunc(const TArray<FString>& Args)
//{
//	Manager::DSMgrActor::GetM().NewActor(TEXT("test"), FVector::ZeroVector, 0.0f);
//}
//
//namespace Manager
//{
//	DSMgrActor::DSMgrActor()
//		: m_uNextGuid(0)
//	{
//
//	}
//
//	bool DSMgrActor::Init()
//	{
//		DS_Regist_Console_Command(TEXT("ds.new"), &NewActorConsolFunc, TEXT(""));
//		return true;
//	}
//
//	bool DSMgrActor::Release()
//	{
//		m_uNextGuid = 0;
//		m_UniqueAndActor.Empty();
//		return true;
//	}
//
//	DSMgrActor::SharedActor DSMgrActor::NewActor(const FName& ActorTid, const FVector& vPos, const float fAngle)
//	{
//		uint32 CurGuid = NextGuid();
//		SharedActor CurActor = SharedActor(new DSActor(CurGuid, nullptr, vPos, fAngle));
//		m_UniqueAndActor.Add(CurGuid, CurActor);
//		return CurActor;
//	}
//
//	uint32 DSMgrActor::NextGuid()
//	{
//		do
//		{
//			++m_uNextGuid;
//			if (0 == m_uNextGuid)
//				++m_uNextGuid;
//		} while (m_UniqueAndActor.Contains(m_uNextGuid));
//
//		return m_uNextGuid;
//	}
//}