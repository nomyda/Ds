#pragma once
#include "DSBuilding.generated.h"

/**
 *
 */

UCLASS()
class DSACTOR_API ADSBuilding : public AActor
{
	GENERATED_BODY()

public:
	ADSBuilding();
	ADSBuilding(const FObjectInitializer& ObjectInitializer);
	virtual ~ADSBuilding();

protected:
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void Tick(float DeltaSeconds) override;

	void Constructor();
	bool InitActor();
	void OnLoadingComplete(const uint32 AsyncLoadID, UObject* pLoadedAsset);

private:
	UPROPERTY(Category = Info, EditAnywhere) FName BuildingTid;
	uint32 m_AsyncLoadID_ActorModel;
};