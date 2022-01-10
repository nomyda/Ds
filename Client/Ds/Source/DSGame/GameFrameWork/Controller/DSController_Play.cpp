#include "DSController_Play.h"
//#include "GameFrameWork/Actor/DSActorInterface.h"
#include "GameFrameWork/Camera/DSPawn_CameraTarget.h"
#include "Manager/Timer/DSTimerMgr.h"
#include "Enum/EnumActor.h"



/*[�۾��ʿ�]
* [�۾���]asdw�� ī�޶� �̵��ϱ�
* �µ巡�׷� ���� ���� �ȿ� �ִ� ĳ���� �����ϱ�
* ��Ŭ������ ĳ���� ����
* ��Ŭ������ ������ ����� ������ ó��
* �´���Ŭ������ ������ ĳ���Ϳ� ������ Ÿ���� ���� ĳ���� ����
* ����Ʈ + �µ巡�׷� ������ ĳ���Ϳ� �߰�
* ��Ŭ������ �̵� ���
*/
void ADSPlayerController_Play::BeginPlay()
{
	m_MoveDirectionBit = static_cast<int32>(EMoveDirection_BitFlag::None);
	m_MoveDirectionBit_Prev = m_MoveDirectionBit;
	bShowMouseCursor = true;
	//bEnableClickEvents = true;
	//bEnableTouchEvents = true;
}

void ADSPlayerController_Play::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (nullptr == InputComponent)
		return;

	InputComponent->BindAction(TEXT("MouseClick"), EInputEvent::IE_Pressed, this, &ADSPlayerController_Play::OnMousePressed);
	InputComponent->BindAction(TEXT("MouseClick"), EInputEvent::IE_Released, this, &ADSPlayerController_Play::OnMouseRelease);
	InputComponent->BindAction(TEXT("Left"), EInputEvent::IE_Pressed, this, &ADSPlayerController_Play::OnPressed_Left);
	InputComponent->BindAction(TEXT("Right"), EInputEvent::IE_Pressed, this, &ADSPlayerController_Play::OnPressed_Right);
	InputComponent->BindAction(TEXT("Forward"), EInputEvent::IE_Pressed, this, &ADSPlayerController_Play::OnPressed_Forward);
	InputComponent->BindAction(TEXT("Backward"), EInputEvent::IE_Pressed, this, &ADSPlayerController_Play::OnPressed_Backward);
	InputComponent->BindAction(TEXT("Left"), EInputEvent::IE_Released, this, &ADSPlayerController_Play::OnReleased_Left);
	InputComponent->BindAction(TEXT("Right"), EInputEvent::IE_Released, this, &ADSPlayerController_Play::OnReleased_Right);
	InputComponent->BindAction(TEXT("Forward"), EInputEvent::IE_Released, this, &ADSPlayerController_Play::OnReleased_Forward);
	InputComponent->BindAction(TEXT("Backward"), EInputEvent::IE_Released, this, &ADSPlayerController_Play::OnReleased_Backward);
	//InputComponent->BindAxis(TEXT("MouseMoveX"), this, &ADSPlayerController_Play::OnMouseMoveX);
	//InputComponent->BindAxis(TEXT("MouseMoveY"), this, &ADSPlayerController_Play::OnMouseMoveY);
}

void ADSPlayerController_Play::OnMousePressed()
{

}

void ADSPlayerController_Play::OnMouseRelease()
{

}

void ADSPlayerController_Play::OnPressed_Left()
{
	OnMove(EMoveDirection_ArrIndex::Left, true);
}

void ADSPlayerController_Play::OnPressed_Right()
{
	OnMove(EMoveDirection_ArrIndex::Right, true);
}

void ADSPlayerController_Play::OnPressed_Forward()
{
	OnMove(EMoveDirection_ArrIndex::Forward, true);
}

void ADSPlayerController_Play::OnPressed_Backward()
{
	OnMove(EMoveDirection_ArrIndex::Backward, true);
}

void ADSPlayerController_Play::OnReleased_Left()
{
	OnMove(EMoveDirection_ArrIndex::Left, false);
}

void ADSPlayerController_Play::OnReleased_Right()
{
	OnMove(EMoveDirection_ArrIndex::Right, false);
}

void ADSPlayerController_Play::OnReleased_Forward()
{
	OnMove(EMoveDirection_ArrIndex::Forward, false);
}

void ADSPlayerController_Play::OnReleased_Backward()
{
	OnMove(EMoveDirection_ArrIndex::Backward, false);
}


//void ADSPlayerController_Play::OnMouseMoveX(float fDelta)
//{
//}
//
//void ADSPlayerController_Play::OnMouseMoveY(float fDelta)
//{
//}

void ADSPlayerController_Play::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	OnMoveInput();
	//if (nullptr == Player)
	//	return;

	//UGameViewportClient* ViewportClient = CastChecked<ULocalPlayer>(Player)->ViewportClient;
	//if (nullptr == ViewportClient)
	//	return;

	//FVector2D vMousePos;
	//if (false == ViewportClient->GetMousePosition(vMousePos))
	//	return;

	//FVector2D vViewportSize;
	//ViewportClient->GetViewportSize(vViewportSize);

	//if (vMousePos.X < 10.0f)
	//	OnLeft();

	//if(vMousePos.X >= vViewportSize.X)
	//	OnRight();

	//if(vMousePos.Y < 10.0f)
	//	OnForward();

	//if(vMousePos.Y >= vViewportSize.Y)
	//	OnBackward();

	//FHitResult HitResult;
	//CurrentClickTraceChannel = DefaultClickTraceChannel;
	//const bool bHit = GetHitResultAtScreenPosition(vMousePos, CurrentClickTraceChannel, true, HitResult);
}

ADSPawn_CameraTarget* ADSPlayerController_Play::_GetObserverActor()
{
	if(m_wpActorInterface.IsValid())
		return m_wpActorInterface.Get();

	m_wpActorInterface.Reset();
	for (TObjectIterator<ADSPawn_CameraTarget> Itr; Itr; ++Itr)
	{
		ADSPawn_CameraTarget* pActor = *Itr;
		if(nullptr == pActor)
			continue;

		m_wpActorInterface = pActor;
		return pActor;
	}

	return nullptr;
}

void ADSPlayerController_Play::OnMove(EMoveDirection_ArrIndex eArrayIndex, const bool bTrueIfPress_Or_FalseIfRelease)
{
	if(eArrayIndex == EMoveDirection_ArrIndex::Max)
		return;

	int32 CurBit = 1 << static_cast<int32>(eArrayIndex);
	if(bTrueIfPress_Or_FalseIfRelease)
		m_MoveDirectionBit = m_MoveDirectionBit | CurBit;
	else
		m_MoveDirectionBit = m_MoveDirectionBit ^ CurBit;
}

void ADSPlayerController_Play::OnMoveInput()
{
	if (m_MoveDirectionBit == m_MoveDirectionBit_Prev)
		return;

	ADSPawn_CameraTarget* pActor = _GetObserverActor();
	if (nullptr == pActor)
		return;

	m_MoveDirectionBit_Prev = m_MoveDirectionBit;
	pActor->Move(m_MoveDirectionBit);
}