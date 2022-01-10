#pragma once
#include "Message/TClassMsg.h"

struct FDsCameraValue_Attach;
struct FDsCameraValue_LookAt;
/*
* 게임인스턴스 Init 함수에서 호출되는 메시지
*/
struct FDsClassMsg_AttachCamera : public TClassMsg<FDsClassMsg_AttachCamera>
{
public:
	typedef TSharedPtr<FDsCameraValue_Attach> spCameraValue_Attach;
	typedef TSharedPtr<FDsCameraValue_LookAt> spCameraValue_LookAt;
	spCameraValue_Attach m_spCameraValue_Attach;
	spCameraValue_LookAt m_spCameraValue_LookAt;
};