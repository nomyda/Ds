#include "DsPlayerCameraManager.h"
#include "Message/DsClassMsg_AttachCamera.h"
#include "Message/DsClassMsg_DetachCamera.h"
#include "Camera/DsCameraValue_Attach.h"
#include "Camera/DsCameraValue_LookAt.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"

ACameraActor* ADsPlayerCameraManager::GetCameraActor()
{
	return AnimCameraActor;
}

void ADsPlayerCameraManager::PreInitializeComponents()
{
	m_hOnAttachCamera = FDsClassMsg_AttachCamera::GetDelegate().AddUObject(this, &ADsPlayerCameraManager::OnAttachCamera);
	m_hOnDetachCamera = FDsClassMsg_DetachCamera::GetDelegate().AddUObject(this, &ADsPlayerCameraManager::OnDetachCamera);
	Super::PreInitializeComponents();
}

void ADsPlayerCameraManager::OnAttachCamera(const FDsClassMsg_AttachCamera& rMsg)
{
	if(rMsg.m_spCameraValue_Attach.IsValid())
		AttachCamera(*rMsg.m_spCameraValue_Attach.Get());
	if (rMsg.m_spCameraValue_LookAt.IsValid())
		LookAtCamera(*rMsg.m_spCameraValue_LookAt.Get());
}

void ADsPlayerCameraManager::OnDetachCamera(const FDsClassMsg_DetachCamera& rMsg)
{

}

void ADsPlayerCameraManager::AttachCamera(const FDsCameraValue_Attach& rValue)
{
	if(false == rValue.m_TargetActor.IsValid())
		return;

	ACameraActor* pCurCameraActor = GetCameraActor();
	if(nullptr == pCurCameraActor)
		return;

	const int32 ArrayIndex = static_cast<int32>(ECameraBlendOrder::Current);
	spCameraValue_Attach& rCurrentValue = m_arrCameraValue_Attach[ArrayIndex];
	if(false == rCurrentValue.IsValid())
	{
		// 현재 카메라가 어태치 되어 있지 않다면,

		// 1. 오프셋 위치를 먼저 구하고
		const FVector vLocation = rValue.m_TargetActor->GetActorLocation();
		const FRotator ActorRot = rValue.m_TargetActor->GetActorRotation();
		const FVector cvOffset = ActorRot.RotateVector(rValue.m_Offset);

		// 2. 카메라 회전방향을 구하고
		const FRotator RotCamera = FRotator(rValue.m_fPitch, rValue.m_fYaw, rValue.m_fRoll);
		FVector vDirCamera = RotCamera.Vector().GetSafeNormal();
		vDirCamera = ActorRot.RotateVector(vDirCamera);

		// 3. 오프셋에서 카메라 회전까지 적용된 위치를 계산한다
		FVector vFollowPos = vLocation + cvOffset;
		vFollowPos = vFollowPos + vDirCamera * rValue.m_fZoom;
		UCameraComponent* pCameraComp = pCurCameraActor->GetCameraComponent();
		if(nullptr == pCameraComp)
			return;

		pCameraComp->SetWorldLocation(vFollowPos, false, nullptr, ETeleportType::TeleportPhysics);
		APlayerController* pOwnerController = GetOwningPlayerController();
		if(nullptr == pOwnerController)
			return;

		pOwnerController->SetViewTargetWithBlend(pCurCameraActor);
	}
	else
	{
		// 현재 카메라가 어태치 되어 있다면,
	}
}

void ADsPlayerCameraManager::LookAtCamera(const FDsCameraValue_LookAt& rValue)
{
}