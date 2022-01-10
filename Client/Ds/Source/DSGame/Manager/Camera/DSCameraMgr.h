#pragma once
#include "Manager/TMgr.h"

enum class ECameraType : int16;
class ADSCamera;
class DSCameraMgr : public TMgr<DSCameraMgr>
{
public:
	DSCameraMgr();
	~DSCameraMgr();

	EMgrIndex GetIndex() const override;
	void OnInit() override;
	void OnShutdown() override;
	void OnTick(float fDeltaSeconds) override;

	void AttachCamera(APawn* pTarget);
	void DetachCamera(APawn* pTarget);

	void Pan(float fValue);
	void Tilt(float fValue);
	void Zoom(float fValue);


private:
	//ADSCamera* SwitchCamera(AActor* pTarget, const ECameraType Type, const float fBlendSec = 0.0f);
	ADSCamera* CreateCamera();
	ADSCamera* GetCamera(const bool bCreate = true);

private:
	ECameraType m_CurCameraType;
	ADSCamera* m_pCurCamera;
};