#pragma once
#include "Message/TClassMsg.h"

/*
* �����ν��Ͻ� Init �Լ����� ȣ��Ǵ� �޽���
*/
struct FDsClassMsg_AttachCamera : public TClassMsg<FDsClassMsg_AttachCamera>
{
public:
	TWeakObjectPtr<APawn> m_TargetPawn;
};