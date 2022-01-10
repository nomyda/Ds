#pragma once

struct FDsCameraValue_Attach
{
public:
	FDsCameraValue_Attach();
	~FDsCameraValue_Attach();

public:
	TWeakObjectPtr<AActor> m_TargetActor;// ��� ����
	FName m_SocketName;// ����
	FVector m_Offset;// Offset
	float m_fZoom;// Zoom
	float m_fYaw;// Yaw
	float m_fPitch;// Pitch
	float m_fRoll;// Roll
	float m_fInitVelocity;// �ʱ� �ӵ�
	float m_fFinalVelocity;// ���� �ӵ�
	float m_fSec_To_FinalVelocity;// ���� �ӵ��� �����ϴ� �ð�
	float m_fBlendSec;// ���� �ð�
};
