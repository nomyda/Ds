#pragma once
#include "Message/TClassMsg.h"

/*
* �����ν��Ͻ� Init �Լ����� ȣ��Ǵ� �޽���
*/
struct FDsClassMsg_DetachCamera : public TClassMsg<FDsClassMsg_DetachCamera>
{
public:
	TWeakObjectPtr<APawn> m_TargetPawn;
};