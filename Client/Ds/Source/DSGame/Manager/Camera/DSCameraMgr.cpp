#include "DSCameraMgr.h"
#include "GameFrameWork/Camera/DSCamera.h"
#include "Table/Camera/DSCameraTable.h"
#include "Manager/Table/DSCameraTableMgr.h"
#include "Manager/Ue4/DSUe4Mgr.h"

DSCameraMgr::DSCameraMgr()
	: m_CurCameraType(ECameraType::Default)
	, m_pCurCamera(nullptr)
{

}

DSCameraMgr::~DSCameraMgr()
{

}

EMgrIndex DSCameraMgr::GetIndex() const 
{
	return EMgrIndex::Camera;
}

void DSCameraMgr::OnInit()
{

}

void DSCameraMgr::OnShutdown() 
{

}

void DSCameraMgr::OnTick(float fDeltaSeconds) 
{
}

void DSCameraMgr::AttachCamera(APawn* pTarget)
{
	ADSCamera* pCamera = GetCamera();
	if (nullptr == pCamera)
		return;

	pCamera->AttachTo(pTarget);
}

void DSCameraMgr::DetachCamera(APawn* pTarget)
{
	ADSCamera* pCamera = GetCamera(false);
	if (nullptr == pCamera)
		return;

	pCamera->Detach();
}

//ADSCamera* DSCameraMgr::SwitchCamera(AActor* pTarget, const ECameraType Type, const float fBlendSec /*= 0.0f*/)
//{
//	bool bCreate = false;
//	if (nullptr == m_pCurCamera)
//	{
//		bCreate = true;
//		m_pCurCamera = CreateCamera(pTarget);
//		if (nullptr == m_pCurCamera)
//			return nullptr;
//	}
//
//	if (m_CurCameraType == Type && false == bCreate)
//		return m_pCurCamera;
//
//	// 카메라 타입 교체
//	const UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECameraType"), true);
//	if (nullptr == pEnum)
//		return nullptr;
//
//	FString CameraTypeName = pEnum->GetNameStringByIndex(static_cast<int32>(Type));
//	FDSCameraTable* pCameraTable = DSCameraTableM::Get().GetTable(*CameraTypeName);
//	if (nullptr == pCameraTable)
//		return nullptr;
//
//	m_pCurCamera->SwitchCameraType(pTarget, pCameraTable, fBlendSec);
//	m_CurCameraType = Type;
//	if (bCreate)
//	{
//		APlayerController* pController =  DSUe4Mgr::Get().GetCurrentPlayerController();
//		if (nullptr == pController)
//			return m_pCurCamera;
//
//		pController->SetViewTargetWithBlend(m_pCurCamera, fBlendSec);
//	}
//
//	return m_pCurCamera;
//}

ADSCamera* DSCameraMgr::CreateCamera()
{
	if (m_pCurCamera)
		return m_pCurCamera;

	UWorld* pWorld = DSUe4Mgr::Get().GetWorld();
	if (nullptr == pWorld)
		return nullptr;

	FActorSpawnParameters SpawnParam;
	SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ADSCamera* pCamera = pWorld->SpawnActor<ADSCamera>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParam);
	return pCamera;
}

ADSCamera* DSCameraMgr::GetCamera(const bool bCreate /*= true*/)
{
	if (nullptr == m_pCurCamera)
	{
		m_pCurCamera = CreateCamera();
	}

	return m_pCurCamera;
}

void DSCameraMgr::Pan(float fValue)
{
	if (nullptr == m_pCurCamera)
		return ;

	m_pCurCamera->Pan(fValue);
}

void DSCameraMgr::Tilt(float fValue)
{
	if (nullptr == m_pCurCamera)
		return;

	m_pCurCamera->Tilt(fValue);
}

void DSCameraMgr::Zoom(float fValue)
{
	if (nullptr == m_pCurCamera)
		return;

	m_pCurCamera->Zoom(fValue);
}
