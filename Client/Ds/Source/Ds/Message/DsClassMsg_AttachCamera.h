#pragma once
#include "Message/TClassMsg.h"

struct FDsCameraValue_Attach;
struct FDsCameraValue_LookAt;
/*
* �����ν��Ͻ� Init �Լ����� ȣ��Ǵ� �޽���
*/
struct FDsClassMsg_AttachCamera : public TClassMsg<FDsClassMsg_AttachCamera>
{
public:
	typedef TSharedPtr<FDsCameraValue_Attach> spCameraValue_Attach;
	typedef TSharedPtr<FDsCameraValue_LookAt> spCameraValue_LookAt;
	spCameraValue_Attach m_spCameraValue_Attach;
	spCameraValue_LookAt m_spCameraValue_LookAt;
};