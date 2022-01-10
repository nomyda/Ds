#pragma once
#include "GameFrameWork/Controller/DSPlayerController.h"
#include "DSController_Play.generated.h"


enum class EMoveDirection_ArrIndex;
class ADSPawn_CameraTarget;
/**
 *
 */ 
UCLASS()
class DS_API ADSPlayerController_Play : public ADSPlayerController
{
	GENERATED_BODY()
public:
	

protected:
	void BeginPlay() override;
	void SetupInputComponent() override;

private:
	void OnMousePressed();
	void OnMouseRelease();
	void OnPressed_Left();
	void OnPressed_Right();
	void OnPressed_Forward();
	void OnPressed_Backward();
	void OnReleased_Left();
	void OnReleased_Right();
	void OnReleased_Forward();
	void OnReleased_Backward();
	//void OnMouseMoveX(float fDelta);
	//void OnMouseMoveY(float fDelta);
	void PlayerTick(float DeltaTime) override;

private:
	ADSPawn_CameraTarget* _GetObserverActor();
	void OnMove(EMoveDirection_ArrIndex eArrayIndex, const bool bTrueIfPress_Or_FalseIfRelease );
	void OnMoveInput();

private:
	TWeakObjectPtr<ADSPawn_CameraTarget> m_wpActorInterface;


	UPROPERTY(meta = (Bitmask, BitmaskEnum = EMoveDirection_BitFlag)) int32 m_MoveDirectionBit;
	UPROPERTY(meta = (Bitmask, BitmaskEnum = EMoveDirection_BitFlag)) int32 m_MoveDirectionBit_Prev;
};