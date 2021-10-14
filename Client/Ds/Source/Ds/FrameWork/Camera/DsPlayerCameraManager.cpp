#include "DsPlayerCameraManager.h"
#include "Message/DsClassMsg_AttachCamera.h"
#include "Message/DsClassMsg_DetachCamera.h"

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

}

void ADsPlayerCameraManager::OnDetachCamera(const FDsClassMsg_DetachCamera& rMsg)
{

}