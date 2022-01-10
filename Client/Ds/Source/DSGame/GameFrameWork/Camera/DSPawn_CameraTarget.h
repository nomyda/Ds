#pragma once
#include "GameFramework/Character.h"
#include "GameFrameWork/Actor/DSActorInterface.h"
#include "DSPawn_CameraTarget.generated.h"

/**
 *
 */
class USphereComponent;
class UCharacterMovementComponent;
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class ADSPawn_CameraTarget : public ACharacter, public IDSActorInterface
{
	GENERATED_BODY()

public:
	ADSPawn_CameraTarget();
	ADSPawn_CameraTarget(const FObjectInitializer& ObjectInitializer);
	~ADSPawn_CameraTarget();

public:
	void Move(const int MoveDirectionBit) override;

protected:
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void Tick(float DeltaSeconds) override;

	void Construct();

	UPROPERTY(VisibleAnywhere) USpringArmComponent* m_SpringArmComp;
	UPROPERTY(VisibleAnywhere) UCameraComponent* m_CameraComp;
};