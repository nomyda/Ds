#pragma once

struct FDsCameraValue_LookAt
{
public:
	FDsCameraValue_LookAt();
	~FDsCameraValue_LookAt();

public:
	TWeakObjectPtr<AActor> m_TargetActor;// ��� ����
	FName m_SocketName;// ����
	FVector m_Offset;// Offset
	float m_fInitVelocity;// �ʱ� �ӵ�
	float m_fFinalVelocity;// ���� �ӵ�
	float m_fSec_To_FinalVelocity;// ���� �ӵ��� �����ϴ� �ð�
	float m_fBlendSec;// ���� �ð�
};
