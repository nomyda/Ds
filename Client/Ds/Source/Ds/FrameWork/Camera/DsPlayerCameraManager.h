#pragma once
#include "Enum/DsEnum_Camera.h"
#include "DsPlayerCameraManager.generated.h"


struct FDsClassMsg_AttachCamera;
struct FDsClassMsg_DetachCamera;
struct FDsCameraValue_Attach;
struct FDsCameraValue_LookAt;

UCLASS()
class ADsPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

public:
	ACameraActor* GetCameraActor();

protected:
	void PreInitializeComponents() override;

private:
	void OnAttachCamera(const FDsClassMsg_AttachCamera& rMsg);
	void OnDetachCamera(const FDsClassMsg_DetachCamera& rMsg);
	void AttachCamera(const FDsCameraValue_Attach& rValue);
	void LookAtCamera(const FDsCameraValue_LookAt& rValue);

private:
	FDelegateHandle m_hOnAttachCamera;
	FDelegateHandle m_hOnDetachCamera;
	typedef TSharedPtr<FDsCameraValue_Attach> spCameraValue_Attach;
	typedef TSharedPtr<FDsCameraValue_LookAt> spCameraValue_LookAt;
	spCameraValue_Attach m_arrCameraValue_Attach[ECameraBlendOrder::Max];
	spCameraValue_LookAt m_arrCameraValue_Value[ECameraBlendOrder::Max];
};