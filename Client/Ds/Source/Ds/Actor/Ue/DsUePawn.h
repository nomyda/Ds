#pragma once
#include "GameFramework/Pawn.h"
#include "IDsUeActorInterface.h"
#include "DsUePawn.generated.h"

/**
 *
 */
class UCapsuleComponent;
UCLASS()
class ADsUePawn : public APawn, public IDsUeActorInterface
{
	GENERATED_BODY()

public:
	ADsUePawn();
	ADsUePawn(const FObjectInitializer& ObjectInitializer);
	~ADsUePawn();

protected:
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void Tick(float DeltaSeconds) override;
};