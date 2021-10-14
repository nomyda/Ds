#pragma once
#include "DsPlayerCameraManager.generated.h"


struct FDsClassMsg_AttachCamera;
struct FDsClassMsg_DetachCamera;

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

private:
	FDelegateHandle m_hOnAttachCamera;
	FDelegateHandle m_hOnDetachCamera;
};