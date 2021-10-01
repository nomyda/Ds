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
	Ds_Regist_Console_Command(TEXT("Ds.Actor.Spawn"), &DsMgr_Actor::OnConsol_SpawnActor, TEXT("Spawn an Actor"));
	Ds_Regist_Console_Command(TEXT("Ds.Actor.DestroyActor"), &DsMgr_Actor::OnConsol_DestroyActor, TEXT("Destroy an Actor"));
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
	FDsActorSpawnParam kParam(FVector::ZeroVector, 0.0f);
	DsMgr_Actor::Get().SpawnActor(kParam);
}

void DsMgr_Actor::OnConsol_DestroyActor(const TArray<FString>& Args)
{
	if (Args.Num() < 1)
		return;

	const FString GuidValue = Args[0];
	if (false == GuidValue.IsNumeric())
		return;

	int32 iGuid = FCString::Atoi(*GuidValue);
	DsMgr_Actor::Get().DestroyActor(iGuid);
}