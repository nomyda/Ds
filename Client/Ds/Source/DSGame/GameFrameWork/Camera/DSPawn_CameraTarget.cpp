#include "DSPawn_CameraTarget.h"
#include "Manager/Camera/DSCameraMgr.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


/*작업할 내용
* 클래스명을 Observer 로 변경하자
* 지금은 해당 클래스에서 위치값을 변경하지만 나중에는 매니저 코드쪽에서 처리하자
* 이동 함수가 호출 되었을때 목표 위치를 셋팅을 하고, 틱에서 이동속도로 보간을 하자
*/
ADSPawn_CameraTarget::ADSPawn_CameraTarget()
	: Super()
{
	Construct();
}

ADSPawn_CameraTarget::ADSPawn_CameraTarget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Construct();
}

ADSPawn_CameraTarget::~ADSPawn_CameraTarget()
{

}

void ADSPawn_CameraTarget::Move(const int MoveDirectionBit)
{
	UCharacterMovementComponent* pMoveComp = FindComponentByClass<UCharacterMovementComponent>();
	if(nullptr == pMoveComp)
		return;
	if(0 == MoveDirectionBit)
	{
		pMoveComp->MaxWalkSpeed = 0.0f;
		return;
	}

	pMoveComp->MaxWalkSpeed = 1000.0f;
}

void ADSPawn_CameraTarget::BeginPlay()
{
	Super::BeginPlay();
	DSCameraMgr::Get().AttachCamera(this);
}

void ADSPawn_CameraTarget::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	DSCameraMgr::Get().DetachCamera(this);
}

void ADSPawn_CameraTarget::Tick(float DeltaSeconds)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f));
}

void ADSPawn_CameraTarget::Construct()
{
	if(nullptr == RootComponent)
		return;

	m_SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring"));
	if(nullptr == m_SpringArmComp)
		return;

	m_SpringArmComp->SetupAttachment(RootComponent);
	m_SpringArmComp->TargetArmLength = 100.0f;
	m_SpringArmComp->bEnableCameraLag = true;
	m_SpringArmComp->CameraLagSpeed = 10.0f;
	m_SpringArmComp->bEnableCameraRotationLag = true;
	m_SpringArmComp->CameraRotationLagSpeed = 10.0f;

	m_CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if(nullptr == m_CameraComp)
		return;

	m_CameraComp->SetupAttachment(m_SpringArmComp);
	m_CameraComp->SetRelativeLocation(FVector(-120.0f, 0.0f, 20.0f));
}
