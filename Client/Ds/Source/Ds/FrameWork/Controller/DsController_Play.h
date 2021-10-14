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
	ADsPlayerController_Play();
	ADsPlayerController_Play(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	void BeginPlay() override;
	void SetupInputComponent() override;
	void SpawnPlayerCameraManager() override;


private:
	void PlayerTick(float DeltaTime) override;
	void Move_Forward_Pressed();
	void Move_Forward_Released();
	void Move_Backward_Pressed();
	void Move_Backward_Released();
	void Move_Left_Pressed();
	void Move_Left_Released();
	void Move_Right_Pressed();
	void Move_Right_Released();
	void MouseRButton_Pressed();
	void MouseRButton_Released();
	void Camera_Pan(float fAxis);
	void Camera_Tilt(float fAxis);
	void Camera_Zoom(float fAxis);

private:
	uint32 m_uiInputBit;
	float m_Camera_Pan;
	float m_Camera_Tilt;
	float m_Camera_Zoom;
};