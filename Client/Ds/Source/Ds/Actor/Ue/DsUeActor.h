#pragma once
#include "GameFramework/Actor.h"
#include "IDsUeActorInterface.h"
#include "DsUeActor.generated.h"

/**
 *
 */
class UCapsuleComponent;
UCLASS()
class ADsUeActor : public AActor, public IDsUeActorInterface
{
	GENERATED_BODY()

public:
	ADsUeActor();
	ADsUeActor(const FObjectInitializer& ObjectInitializer);
	~ADsUeActor();

protected:
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void Tick(float DeltaSeconds) override;

	void InitUeActor(const FName& m_ActorTid) override {}
	void ShutdownUeActor() override {}
};