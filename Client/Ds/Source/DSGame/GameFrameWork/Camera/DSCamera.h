#pragma once
#include "Camera/CameraActor.h"
#include "DSCamera.generated.h"

struct FDSCameraTable;

struct DSCameraTarget_To_Follow
{
public:
	DSCameraTarget_To_Follow();
	DSCameraTarget_To_Follow(AActor* pTarget);
	DSCameraTarget_To_Follow(const FVector& Target, const FRotator& Rot);
	void SetTarget_To_Follow(AActor* pTarget);
	void SetTarget_To_Follow(const FVector& Target, const FRotator& Rot);
	FVector GetLocation() const;
	FRotator GetRotation() const;

private:
	bool m_bTrue_If_TargetIsActor;
	TWeakObjectPtr<AActor> m_wTargetActorPtr;
	FVector m_vTargetPos;
	FRotator m_TargetRot;
};

struct DSCameraValue
{
public:
	DSCameraValue();

public:
	DSCameraTarget_To_Follow m_Target_To_Follow;
	FVector m_LookAtOffset_From_Target;
	FRotator m_Rotator_From_Target;
	float m_Zoom;
};

UCLASS()
class ADSCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	ADSCamera();
	ADSCamera(const FObjectInitializer& ObjectInitializer);
	~ADSCamera();
	void Constructor();

	void AttachTo(AActor* pTarget);
	void AttachTo(const FVector& Target);
	void Detach();
	void SwitchCameraType(AActor* pTarget, const FDSCameraTable* pCameraTable, const float fBlendSec = 0.0f);
	void SwitchCameraType(const FVector& Target, const FRotator& Rot, const FDSCameraTable* pCameraTable, const float fBlendSec = 0.0f);

	void Pan(float fValue);
	void Tilt(float fValue);
	void Zoom(float fValue);


protected:
	void Tick(float DeltaSeconds) override;


private:
	void SwitchCameraType(const DSCameraTarget_To_Follow& rTarget, const FDSCameraTable* pCameraTable, const float fBlendSec = 0.0f);
	void Update_Pan(const float fCurSec);
	void Update_Tilt(const float fCurSec);
	void Update_Zoom(const float fCurSec);
	void UpdateCameraValue(const DSCameraValue& rValue);

private:
	typedef TSharedPtr<DSCameraValue> SharedCameraValuePtr;
	SharedCameraValuePtr m_CurrentValue;
	SharedCameraValuePtr m_NextValue;
	float m_fBlendSec_Pan;
	float m_fBlendSec_Tilt;
	float m_fBlendSec_Zoom;
};