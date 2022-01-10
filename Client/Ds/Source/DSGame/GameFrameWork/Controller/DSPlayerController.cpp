#include "DSPlayerController.h"
#include "Manager/Camera/DSCameraMgr.h"


ADSPlayerController::ADSPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, m_bRMouseBtnPressed(false)
{

}

void ADSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (nullptr == InputComponent)
		return;

	InputComponent->BindAction(TEXT("LMouseBtn"), EInputEvent::IE_Pressed, this, &ADSPlayerController::LMouseBtnPressed);
	InputComponent->BindAction(TEXT("LMouseBtn"), EInputEvent::IE_Released, this, &ADSPlayerController::LMouseBtnReleased);
	InputComponent->BindAction(TEXT("RMouseBtn"), EInputEvent::IE_Pressed, this, &ADSPlayerController::RMouseBtnPressed);
	InputComponent->BindAction(TEXT("RMouseBtn"), EInputEvent::IE_Released, this, &ADSPlayerController::RMouseBtnReleased);
	InputComponent->BindAxis(TEXT("CameraPan"), this, &ADSPlayerController::CameraPan);
	InputComponent->BindAxis(TEXT("CameraTilt"), this, &ADSPlayerController::CameraTilt);
	InputComponent->BindAxis(TEXT("CameraZoom"), this, &ADSPlayerController::CameraZoom);
}

void ADSPlayerController::LMouseBtnPressed()
{

}

void ADSPlayerController::LMouseBtnReleased()
{

}

void ADSPlayerController::RMouseBtnPressed()
{
	m_bRMouseBtnPressed = true;
}

void ADSPlayerController::RMouseBtnReleased()
{
	m_bRMouseBtnPressed = false;
}

void ADSPlayerController::CameraPan(float fValue)
{
	if (false == m_bRMouseBtnPressed)
		return;

	DSCameraMgr::Get().Pan(fValue);
}

void ADSPlayerController::CameraTilt(float fValue)
{
	if (false == m_bRMouseBtnPressed)
		return;

	DSCameraMgr::Get().Tilt(fValue);
}

void ADSPlayerController::CameraZoom(float fValue)
{
	DSCameraMgr::Get().Zoom(fValue);
}