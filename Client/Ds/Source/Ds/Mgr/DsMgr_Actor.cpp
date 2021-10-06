#include "DsMgr_Actor.h"
#include "Actor/DsActor.h"
#include "Mgr/ClientVariable/DsClientVariableMgr.h"
#include "Actor/DsActorSpawnParam.h"

DsMgr_Actor::DsMgr_Actor()
	: m_iNextGuid(0)
{

}

DsMgr_Actor::~DsMgr_Actor()
{

}

int32 DsMgr_Actor::SpawnActor(const FDsActorSpawnParam& rParam)
{
	const int32 CurGuid = NextGuid();
	SharedActor CurActor = SharedActor(new DsActor(CurGuid));
	m_UniqueAndActor.Add(CurGuid, CurActor);
	CurActor->InitActor(rParam);
	return CurGuid;
}

bool DsMgr_Actor::DestroyActor(const int32 iGuid)
{
	if (false == m_UniqueAndActor.Contains(iGuid))
		return false;

	m_UniqueAndActor.Remove(iGuid);
	return true;
}

DsActor* DsMgr_Actor::GetActor(const int32 iGuid)
{
	return nullptr;
}

EMgr_Index DsMgr_Actor::GetIndex() const
{
	return EMgr_Index::Actor;
}

void DsMgr_Actor::OnInit()
{
#if UE_EDITOR
	Ds_Regist_Console_Command(TEXT("Ds.Actor.Spawn"), &DsMgr_Actor::OnConsol_SpawnActor, TEXT("Spawn an Actor, {0} is Tid, {1} is X, {2} is Y, {3} is Z, {4} is Angle"));
	Ds_Regist_Console_Command(TEXT("Ds.Actor.DestroyActor"), &DsMgr_Actor::OnConsol_DestroyActor, TEXT("Destroy an Actor"));
#endif
}

void DsMgr_Actor::OnTick(float fDeltaSeconds)
{
	for (auto CurPair : m_UniqueAndActor)
	{
		auto& CurActor = CurPair.Value;
		if (false == CurActor.IsValid())
			continue;

		CurActor->OnTick(fDeltaSeconds);
	}
}

int32 DsMgr_Actor::NextGuid()
{
	do
	{
		++m_iNextGuid;
		if (0 >= m_iNextGuid)
			m_iNextGuid = 1;


	} while (m_UniqueAndActor.Contains(m_iNextGuid));

	return m_iNextGuid;
}

void DsMgr_Actor::OnConsol_SpawnActor(const TArray<FString>& Args)
{
	FName Tid;
	FVector vPos = FVector::ZeroVector;
	float fAngle = 0.0f;

	int32 iArgIndex = 0;
	if (Args.Num() > iArgIndex)
	{
		Tid = *Args[iArgIndex];
		++iArgIndex;
	}
	for (int32 iIndex = 0; iIndex < 3; ++iIndex)
	{
		if (Args.Num() > iArgIndex)
		{
			if (Args[iArgIndex].IsNumeric())
				vPos[iIndex] = FCString::Atof(*Args[iArgIndex]);
		}

		++iArgIndex;
	}
	if (Args.Num() > iArgIndex)
	{
		if (Args[iArgIndex].IsNumeric())
			fAngle = FCString::Atof(*Args[iArgIndex]);
	}

	FDsActorSpawnParam kParam(Tid, vPos, fAngle);
	DsMgr_Actor::Get().SpawnActor(kParam);
	DsLog(TEXT("actor"), ELogVerbosity::Log, TEXT("Complete"));
}

void DsMgr_Actor::OnConsol_DestroyActor(const TArray<FString>& Args)
{
	if (0 == Args.Num())
	{
		DsLog(TEXT("actor"), ELogVerbosity::Warning, TEXT("0 == Args.Num()"));
		return;
	}

	const FString GuidValue = Args[0];
	if (false == GuidValue.IsNumeric())
	{
		DsLog(TEXT("actor"), ELogVerbosity::Warning, TEXT("false == GuidValue.IsNumeric()"));
		return;
	}

	int32 iGuid = FCString::Atoi(*GuidValue);
	DsMgr_Actor::Get().DestroyActor(iGuid);
	DsLog(TEXT("actor"), ELogVerbosity::Log, TEXT("Complete"));
}