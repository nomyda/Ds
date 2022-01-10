// Fill out your copyright notice in the Description page of Project Settings.


#include "DsPawn_Camera.h"
#include "Message/DsClassMsg_AttachCamera.h"
#include "Message/DsClassMsg_DetachCamera.h"
#include "Enum/DsEnum_Input.h"
#include "Mgr/FrameWork/DsFrameWorkMgr.h"
#include "Camera/DsCameraValue_Attach.h"
#include "Camera/DsCameraValue_LookAt.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
ADsPawn_Camera::ADsPawn_Camera()
	: Super()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Constructor();
}

ADsPawn_Camera::ADsPawn_Camera(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Constructor();
}

void ADsPawn_Camera::Move(const uint32 uiMoveBit)
{
	FVector vMoveDirection = FVector::ZeroVector;
	if(uiMoveBit & static_cast<uint32>(EInputBitType::Move_Forward))
	{	
		vMoveDirection.X += 1.0f;
	}
	if(uiMoveBit & static_cast<uint32>(EInputBitType::Move_Backward))
	{
		vMoveDirection.X += -1.0f;
	}
	if (uiMoveBit & static_cast<uint32>(EInputBitType::Move_Left))
	{
		vMoveDirection.Y += -1.0f;
	}
	if (uiMoveBit & static_cast<uint32>(EInputBitType::Move_Right))
	{
		vMoveDirection.Y += 1.0f;
	}

	const float DirectionSize = vMoveDirection.Size();

	UPawnMovementComponent* pMoveComponent = GetMovementComponent();
	if(pMoveComponent)
	{
		pMoveComponent->Velocity = vMoveDirection;
	}
	//UWorld* pWorld = DsFrameWorkMgr::Get().GetWorld();
	//if(nullptr == pWorld)
	//	return;

	//static const float InitSpeed = 0.0f;
	//static const float FinalSpeed = 100.0f;
	//static const float FinalSec = 5.0f;
	//const float fDeltaSec = pWorld->GetDeltaSeconds();
	//CurSec += fDeltaSec;
	//CurSec = FMath::Min(CurSec, FinalSec);
	//const float Acceleration = FinalSpeed / FinalSec;
	//const float CurVelocity = InitSpeed + (Acceleration* CurSec);
}

// Called when the game starts or when spawned
void ADsPawn_Camera::BeginPlay()
{
	FDsClassMsg_AttachCamera kAttachCamera;
	// 어태치 셋팅
	kAttachCamera.m_spCameraValue_Attach = FDsClassMsg_AttachCamera::spCameraValue_Attach(new FDsCameraValue_Attach);
	kAttachCamera.m_spCameraValue_Attach->m_TargetActor = this;
	kAttachCamera.m_spCameraValue_Attach->m_Offset = FVector(10.0f, 0.0f, 0.0f);
	kAttachCamera.m_spCameraValue_Attach->m_fZoom = 200.0f;// Zoom
	kAttachCamera.m_spCameraValue_Attach->m_fYaw = 0.0f;// Yaw
	kAttachCamera.m_spCameraValue_Attach->m_fPitch = -45.0f;// Pitch
	kAttachCamera.m_spCameraValue_Attach->m_fRoll = 0.0f;// Roll
	kAttachCamera.m_spCameraValue_Attach->m_fInitVelocity = 10.0f;// 초기 속도
	kAttachCamera.m_spCameraValue_Attach->m_fFinalVelocity = 500.0f;// 최종 속도
	kAttachCamera.m_spCameraValue_Attach->m_fSec_To_FinalVelocity = 1.0f;// 최종 속도에 도달하는 시간
	kAttachCamera.m_spCameraValue_Attach->m_fBlendSec = 1.0f;// 블렌딩 시간
	// 룩엣 셋팅
	kAttachCamera.m_spCameraValue_LookAt = FDsClassMsg_AttachCamera::spCameraValue_LookAt(new FDsCameraValue_LookAt);
	kAttachCamera.m_spCameraValue_LookAt->m_TargetActor = this;// 대상 액터
	kAttachCamera.m_spCameraValue_LookAt->m_Offset = FVector(50.0f, 0.0f, 10.0f);// Offset
	kAttachCamera.m_spCameraValue_LookAt->m_fInitVelocity = 10.0f;// 초기 속도
	kAttachCamera.m_spCameraValue_LookAt->m_fFinalVelocity = 500.0f;// 최종 속도
	kAttachCamera.m_spCameraValue_LookAt->m_fSec_To_FinalVelocity = 1.0f;// 최종 속도에 도달하는 시간
	kAttachCamera.m_spCameraValue_LookAt->m_fBlendSec = 1.0f;// 블렌딩 시간
	kAttachCamera.Send();

	Super::BeginPlay();
}

void ADsPawn_Camera::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	FDsClassMsg_DetachCamera kDetachCamera;
	kDetachCamera.m_TargetPawn = this;
	kDetachCamera.Send();

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ADsPawn_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADsPawn_Camera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADsPawn_Camera::Constructor()
{
	m_StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	if(nullptr == RootComponent)
		RootComponent = m_StaticMesh;
	else
		m_StaticMesh->SetupAttachment(RootComponent);

	UPawnMovementComponent* pMoveComponent = GetMovementComponent();
	if(pMoveComponent)
	{
		pMoveComponent->MaxWalk
	}
}
