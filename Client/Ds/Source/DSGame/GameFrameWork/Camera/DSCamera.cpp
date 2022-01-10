#include "DSCamera.h"
#include "Table/Camera/DSCameraTable.h"
#include "Camera/CameraComponent.h"
#include "Manager/Timer/DSTimerMgr.h"

/* 필요 항목
* => 원점/방향, 원점에서 바라볼곳 오프셋, Yaw/Pitch/Roll, Length(Zoom)
*/ 
DSCameraTarget_To_Follow::DSCameraTarget_To_Follow()
	: m_bTrue_If_TargetIsActor(true)
	, m_vTargetPos(FVector::ZeroVector)
	, m_TargetRot(FRotator::ZeroRotator)
{

}

DSCameraTarget_To_Follow::DSCameraTarget_To_Follow(AActor* pTarget)
{
	SetTarget_To_Follow(pTarget);
}

DSCameraTarget_To_Follow::DSCameraTarget_To_Follow(const FVector& Target, const FRotator& Rot)
{
	SetTarget_To_Follow(Target, Rot);
}

void DSCameraTarget_To_Follow::SetTarget_To_Follow(AActor* pTarget)
{
	m_bTrue_If_TargetIsActor = false;
	m_wTargetActorPtr = TWeakObjectPtr<AActor>(pTarget);
	m_vTargetPos = FVector::ZeroVector;
	m_TargetRot = FRotator::ZeroRotator;
}

void DSCameraTarget_To_Follow::SetTarget_To_Follow(const FVector& Target, const FRotator& Rot)
{
	m_bTrue_If_TargetIsActor = false;
	m_wTargetActorPtr.Reset();
	m_vTargetPos = Target;
	m_TargetRot = Rot;
}

FVector DSCameraTarget_To_Follow::GetLocation() const
{
	if (m_bTrue_If_TargetIsActor)
	{
		if (false == m_wTargetActorPtr.IsValid())
			return FVector::ZeroVector;

		return m_wTargetActorPtr->GetActorLocation();
	}

	return m_vTargetPos;
}

FRotator DSCameraTarget_To_Follow::GetRotation() const
{
	if (m_bTrue_If_TargetIsActor)
	{
		if (false == m_wTargetActorPtr.IsValid())
			return FRotator::ZeroRotator;

		return m_wTargetActorPtr->GetActorRotation();
	}

	return m_TargetRot;
}

DSCameraValue::DSCameraValue()
	: m_LookAtOffset_From_Target(FVector::ZeroVector)
	, m_Rotator_From_Target(FRotator::ZeroRotator)
	, m_Zoom(0.0f)
{

}


ADSCamera::ADSCamera()
	: Super()
{
	Constructor();
}

ADSCamera::ADSCamera(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Constructor();
}

ADSCamera::~ADSCamera()
{

}

void ADSCamera::Constructor()
{
	m_fBlendSec_Pan = 0.0f;
	m_fBlendSec_Tilt = 0.0f;
	m_fBlendSec_Zoom = 0.0f;
	PrimaryActorTick.bCanEverTick = true;
}

void ADSCamera::AttachTo(AActor* pTarget)
{

}

void ADSCamera::AttachTo(const FVector& Target)
{

}

void ADSCamera::Detach()
{

}

void ADSCamera::SwitchCameraType(AActor* pTarget, const FDSCameraTable* pCameraTable, const float fBlendSec /*= 0.0f*/)
{
	SwitchCameraType(DSCameraTarget_To_Follow(pTarget), pCameraTable, fBlendSec);
}

void ADSCamera::SwitchCameraType(const FVector& Target, const FRotator& Rot, const FDSCameraTable* pCameraTable, const float fBlendSec /*= 0.0f*/)
{
	SwitchCameraType(DSCameraTarget_To_Follow(Target, Rot), pCameraTable, fBlendSec);
}

void ADSCamera::SwitchCameraType(const DSCameraTarget_To_Follow& rTarget, const FDSCameraTable* pCameraTable, const float fBlendSec /*= 0.0f*/)
{
	if (nullptr == pCameraTable)
		return;

	UCameraComponent* pCamera = GetCameraComponent();
	if (nullptr == pCamera)
		return;

	if (false == m_CurrentValue.IsValid())
	{
		pCamera->FieldOfView = pCameraTable->Settings.FieldOfView;
		pCamera->bConstrainAspectRatio = pCameraTable->Settings.bConstrainAspectRatio;
		pCamera->AspectRatio = pCameraTable->Settings.AspectRatio;
		pCamera->PostProcessBlendWeight = pCameraTable->Settings.PostProcessBlendWeight;
		//m_CurrentValue = SharedCameraValuePtr(new DSCameraValue);
		//m_CurrentValue->m_Target_To_Follow = rTarget;
		//m_CurrentValue->m_LookAtOffset_From_Target = pCameraTable->LookAtOffset_From_Target;
		//m_CurrentValue->m_Rotator_From_Target = pCameraTable->Rotator_From_Target;
		//m_CurrentValue->m_Zoom = pCameraTable->ZoomDefault;
		//UpdateCameraValue(*m_CurrentValue.Get());
	}
}

void ADSCamera::Pan(float fValue)
{
	if (false == m_CurrentValue.IsValid() || fValue == 0.0f)
		return;

	if (false == m_NextValue.IsValid())
	{
		m_NextValue = SharedCameraValuePtr(new DSCameraValue);
		*m_NextValue.Get() = *m_CurrentValue.Get();
	}

	static const float YawValue = 10.0f;
	m_NextValue->m_Rotator_From_Target.Yaw = m_NextValue->m_Rotator_From_Target.Yaw + (YawValue*fValue);
	m_fBlendSec_Pan = DSTimerMgr::Get().GetRealTimeSeconds();
}

void ADSCamera::Tilt(float fValue)
{
	return;
	if (false == m_CurrentValue.IsValid() || fValue == 0.0f)
		return;

	if (false == m_NextValue.IsValid())
	{
		m_NextValue = SharedCameraValuePtr(new DSCameraValue);
		*m_NextValue.Get() = *m_CurrentValue.Get();
	}

	static const float PtichValue = 30.0f;
	m_NextValue->m_Rotator_From_Target.Pitch = m_NextValue->m_Rotator_From_Target.Pitch + (PtichValue*fValue);
	m_fBlendSec_Tilt = DSTimerMgr::Get().GetRealTimeSeconds();
}

void ADSCamera::Zoom(float fValue)
{
	if (false == m_CurrentValue.IsValid() || fValue == 0.0f)
		return;

	if (false == m_NextValue.IsValid())
	{
		m_NextValue = SharedCameraValuePtr(new DSCameraValue);
		*m_NextValue.Get() = *m_CurrentValue.Get();
	}

	static const float ZoomValue = 100.0f;
	m_NextValue->m_Zoom = m_NextValue->m_Zoom + (ZoomValue*fValue);
	m_fBlendSec_Zoom = DSTimerMgr::Get().GetRealTimeSeconds();
}

void ADSCamera::Tick(float DeltaSeconds)
{
	if (m_fBlendSec_Pan <= 0.0f && m_fBlendSec_Tilt <= 0.0f && m_fBlendSec_Zoom <= 0.0f)
		return;

	const float fCurSec = DSTimerMgr::Get().GetRealTimeSeconds();
	Update_Pan(fCurSec);
	Update_Tilt(fCurSec);
	Update_Zoom(fCurSec);	
	if (m_CurrentValue.IsValid())
	{
		UpdateCameraValue(*m_CurrentValue.Get());
	}
}

void ADSCamera::Update_Pan(const float fCurSec)
{
	if (m_fBlendSec_Pan <= 0.0f || false == m_CurrentValue.IsValid() || false == m_NextValue.IsValid())
		return;

	const float fPassedSec = fCurSec - m_fBlendSec_Pan;
	m_CurrentValue->m_Rotator_From_Target.Yaw = FMath::FInterpTo(m_CurrentValue->m_Rotator_From_Target.Yaw, m_NextValue->m_Rotator_From_Target.Yaw, fPassedSec, 1.0f);
	if (fPassedSec > 1.0f)
		m_fBlendSec_Pan = 0.0f;
}

void ADSCamera::Update_Tilt(const float fCurSec)
{
	if (m_fBlendSec_Tilt <= 0.0f || false == m_CurrentValue.IsValid() || false == m_NextValue.IsValid())
		return;

	const float fPassedSec = fCurSec - m_fBlendSec_Tilt;
	m_CurrentValue->m_Rotator_From_Target.Pitch = FMath::FInterpTo(m_CurrentValue->m_Rotator_From_Target.Pitch, m_NextValue->m_Rotator_From_Target.Pitch, fPassedSec, 1.0f);
	if (fPassedSec > 1.0f)
		m_fBlendSec_Tilt = 0.0f;
}

void ADSCamera::Update_Zoom(const float fCurSec)
{
	if (m_fBlendSec_Zoom <= 0.0f || false == m_CurrentValue.IsValid() || false == m_NextValue.IsValid())
		return;

	const float fPassedSec = fCurSec - m_fBlendSec_Zoom;
	m_CurrentValue->m_Zoom = FMath::FInterpTo(m_CurrentValue->m_Zoom, m_NextValue->m_Zoom, fPassedSec, 1.0f);
	if (fPassedSec > 1.0f)
		m_fBlendSec_Zoom = 0.0f;
}

void ADSCamera::UpdateCameraValue(const DSCameraValue& rValue)
{
	FVector vDir_For_CameraPos = -rValue.m_Rotator_From_Target.Vector();
	vDir_For_CameraPos.Normalize();

	// 카메라 위치
	const FVector vNewLocation = rValue.m_Target_To_Follow.GetLocation() + (vDir_For_CameraPos * rValue.m_Zoom);
	SetActorLocation(vNewLocation);

	// 카메라 방향
	const FRotator NewRot = rValue.m_Target_To_Follow.GetRotation();
	FVector vDir_For_LookAt = NewRot.Vector();
	vDir_For_LookAt.Normalize();
	const FVector vLookAtPos = rValue.m_Target_To_Follow.GetLocation() + (vDir_For_LookAt * rValue.m_LookAtOffset_From_Target);
	FVector vDir_LookAt = vLookAtPos - vNewLocation;
	vDir_LookAt.Normalize();
	this->SetActorRotation(vDir_LookAt.Rotation());
}