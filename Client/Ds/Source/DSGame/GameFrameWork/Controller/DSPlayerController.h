#pragma once
#include "GameFramework/PlayerController.h"
#include "DSPlayerController.generated.h"

/**
 *
 */
UCLASS()
class DS_API ADSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADSPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	void SetupInputComponent() override;

private:
	void LMouseBtnPressed();
	void LMouseBtnReleased();
	void RMouseBtnPressed();
	void RMouseBtnReleased();
	void CameraPan(float fValue);
	void CameraTilt(float fValue);
	void CameraZoom(float fValue);

private:
	bool m_bRMouseBtnPressed;
};