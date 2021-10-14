#pragma once
#include "Message/TClassMsg.h"

/*
* 게임인스턴스 Init 함수에서 호출되는 메시지
*/
struct FDsClassMsg_DetachCamera : public TClassMsg<FDsClassMsg_DetachCamera>
{
public:
	TWeakObjectPtr<APawn> m_TargetPawn;
};