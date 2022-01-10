#pragma once
#include "GameFramework/Actor.h"
#include "DSActorInterface.h"
#include "DSActor.generated.h"

USTRUCT()
struct FActorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) FName ActorTid;
};

/**
 *
 */
UCLASS()
class DSCOREFRAMEWORK_API ADSActor : public AActor
{
	GENERATED_BODY()

public:
	ADSActor();
	ADSActor(const FObjectInitializer& ObjectInitializer);
	virtual ~ADSActor();

protected:
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere) FActorInfo m_Info;
	UPROPERTY(EditAnywhere) FName ActorTid;
};