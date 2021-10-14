#include "DsController_Play.h"
#include "FrameWork/Camera/DsPlayerCameraManager.h"
#include "Enum/DsEnum_Input.h"



/*[작업필요]
* [작업중]asdw로 카메라 이동하기
* 좌드래그로 선택 영역 안에 있는 캐릭터 선택하기
* 좌클릭으로 캐릭터 선택
* 좌클릭으로 선택한 명령이 있을때 처리
* 좌더블클릭으로 선택한 캐릭터와 동일한 타입의 여러 캐릭터 선택
* 시프트 + 좌드래그로 선택한 캐릭터에 추가
* 우클릭으로 이동 명령
*/
ADsPlayerController_Play::ADsPlayerController_Play()
: Super()
, m_uiInputBit(0)
, m_Camera_Pan(0.0f)
, m_Camera_Tilt(0.0f)
, m_Camera_Zoom(0.0f)
{

}

ADsPlayerController_Play::ADsPlayerController_Play(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
: Super(ObjectInitializer)
, m_uiInputBit(0)
, m_Camera_Pan(0.0f)
, m_Camera_Tilt(0.0f)
, m_Camera_Zoom(0.0f)
{

}

void ADsPlayerController_Play::BeginPlay()
{
}

void ADsPlayerController_Play::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (nullptr == InputComponent)
		return;

	InputComponent->BindAction(TEXT("Move_Forward"), EInputEvent::IE_Pressed, this, &ADsPlayerController_Play::Move_Forward_Pressed);
	InputComponent->BindAction(TEXT("Move_Forward"), EInputEvent::IE_Released, this, &ADsPlayerController_Play::Move_Forward_Released);
	InputComponent->BindAction(TEXT("Move_Backward"), EInputEvent::IE_Pressed, this, &ADsPlayerController_Play::Move_Backward_Pressed);
	InputComponent->BindAction(TEXT("Move_Backward"), EInputEvent::IE_Released, this, &ADsPlayerController_Play::Move_Backward_Released);
	InputComponent->BindAction(TEXT("Move_Left"), EInputEvent::IE_Pressed, this, &ADsPlayerController_Play::Move_Left_Pressed);
	InputComponent->BindAction(TEXT("Move_Left"), EInputEvent::IE_Released, this, &ADsPlayerController_Play::Move_Left_Released);
	InputComponent->BindAction(TEXT("Move_Right"), EInputEvent::IE_Pressed, this, &ADsPlayerController_Play::Move_Right_Pressed);
	InputComponent->BindAction(TEXT("Move_Right"), EInputEvent::IE_Released, this, &ADsPlayerController_Play::Move_Right_Released);
	InputComponent->BindAction(TEXT("MouseRButton"), EInputEvent::IE_Pressed, this, &ADsPlayerController_Play::MouseRButton_Pressed);
	InputComponent->BindAction(TEXT("MouseRButton"), EInputEvent::IE_Released, this, &ADsPlayerController_Play::MouseRButton_Released);
	InputComponent->BindAxis(TEXT("Camera_Pan"), this, &ADsPlayerController_Play::Camera_Pan);
	InputComponent->BindAxis(TEXT("Camera_Tilt"), this, &ADsPlayerController_Play::Camera_Tilt);
	InputComponent->BindAxis(TEXT("Camera_Zoom"), this, &ADsPlayerController_Play::Camera_Zoom);
}

void ADsPlayerController_Play::SpawnPlayerCameraManager()
{
	PlayerCameraManagerClass = ADsPlayerCameraManager::StaticClass();
	Super::SpawnPlayerCameraManager();
}

void ADsPlayerController_Play::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ADsPlayerController_Play::Move_Forward_Pressed()
{
	m_uiInputBit |= static_cast<uint32>(EInputBitType::Move_Forward);
}

void ADsPlayerController_Play::Move_Forward_Released()
{
	m_uiInputBit ^= static_cast<uint32>(EInputBitType::Move_Forward);
}

void ADsPlayerController_Play::Move_Backward_Pressed()
{
	m_uiInputBit |= static_cast<uint32>(EInputBitType::Move_Backward);
}

void ADsPlayerController_Play::Move_Backward_Released()
{
	m_uiInputBit ^= static_cast<uint32>(EInputBitType::Move_Backward);
}

void ADsPlayerController_Play::Move_Left_Pressed()
{
	m_uiInputBit |= static_cast<uint32>(EInputBitType::Move_Left);
}

void ADsPlayerController_Play::Move_Left_Released()
{
	m_uiInputBit ^= static_cast<uint32>(EInputBitType::Move_Left);
}

void ADsPlayerController_Play::Move_Right_Pressed()
{
	m_uiInputBit |= static_cast<uint32>(EInputBitType::Move_Right);
}

void ADsPlayerController_Play::Move_Right_Released()
{
	m_uiInputBit ^= static_cast<uint32>(EInputBitType::Move_Right);
}

void ADsPlayerController_Play::MouseRButton_Pressed()
{
	m_uiInputBit |= static_cast<uint32>(EInputBitType::MouseRButton_Pressed);
}

void ADsPlayerController_Play::MouseRButton_Released()
{
	m_uiInputBit ^= static_cast<uint32>(EInputBitType::MouseRButton_Pressed);
}

void ADsPlayerController_Play::Camera_Pan(float fAxis)
{
	m_Camera_Pan = fAxis;
}

void ADsPlayerController_Play::Camera_Tilt(float fAxis)
{
	m_Camera_Tilt = fAxis;
}

void ADsPlayerController_Play::Camera_Zoom(float fAxis)
{
	m_Camera_Zoom = fAxis;
}