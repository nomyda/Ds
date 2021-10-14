#pragma once
#include "Message/TClassMsg.h"

/*
* 게임인스턴스 Init 함수에서 호출되는 메시지
*/
struct FDsClassMsg_AttachCamera : public TClassMsg<FDsClassMsg_AttachCamera>
{
public:
	TWeakObjectPtr<APawn> m_TargetPawn;
};