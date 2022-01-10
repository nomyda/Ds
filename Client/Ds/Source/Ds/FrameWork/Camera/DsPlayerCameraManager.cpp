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
		// ���� ī�޶� ����ġ �Ǿ� ���� �ʴٸ�,

		// 1. ������ ��ġ�� ���� ���ϰ�
		const FVector vLocation = rValue.m_TargetActor->GetActorLocation();
		const FRotator ActorRot = rValue.m_TargetActor->GetActorRotation();
		const FVector cvOffset = ActorRot.RotateVector(rValue.m_Offset);

		// 2. ī�޶� ȸ�������� ���ϰ�
		const FRotator RotCamera = FRotator(rValue.m_fPitch, rValue.m_fYaw, rValue.m_fRoll);
		FVector vDirCamera = RotCamera.Vector().GetSafeNormal();
		vDirCamera = ActorRot.RotateVector(vDirCamera);

		// 3. �����¿��� ī�޶� ȸ������ ����� ��ġ�� ����Ѵ�
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
		// ���� ī�޶� ����ġ �Ǿ� �ִٸ�,
	}
}

void ADsPlayerCameraManager::LookAtCamera(const FDsCameraValue_LookAt& rValue)
{
}