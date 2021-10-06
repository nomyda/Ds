#pragma once
#include "GameFramework/PlayerController.h"
#include "DsController_Play.generated.h"


enum class EMoveDirection_ArrIndex;
class ADSPawn_CameraTarget;
/**
 *
 */ 
UCLASS()
class ADsPlayerController_Play : public APlayerController
{
	GENERATED_BODY()
public:
	

protected:
	void BeginPlay() override;
	void SetupInputComponent() override;

private:
	void PlayerTick(float DeltaTime) override;
};