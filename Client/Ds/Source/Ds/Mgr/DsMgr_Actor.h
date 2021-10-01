#pragma once
#include "Mgr/TMgr.h"
struct FDsActorSpawnParam;
class DsActor;
class DS_API DsMgr_Actor : public TMgr<DsMgr_Actor>
{
public:
	DsMgr_Actor();
	~DsMgr_Actor();

	int32 SpawnActor(const FDsActorSpawnParam& rParam);
	bool DestroyActor(const int32 iGuid);
	DsActor* GetActor(const int32 iGuid);

	EMgr_Index GetIndex() const override;

protected:
	void OnInit() override;
	int32 NextGuid();

	static void OnConsol_SpawnActor(const TArray<FString>& Args);
	static void OnConsol_DestroyActor(const TArray<FString>& Args);

private:
	typedef TSharedPtr<DsActor> SharedActor;
	TSortedMap<uint32, SharedActor> m_UniqueAndActor;
	int32 m_iNextGuid;
};