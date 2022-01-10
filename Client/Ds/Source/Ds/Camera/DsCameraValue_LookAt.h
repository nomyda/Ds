#pragma once

struct FDsCameraValue_LookAt
{
public:
	FDsCameraValue_LookAt();
	~FDsCameraValue_LookAt();

public:
	TWeakObjectPtr<AActor> m_TargetActor;// 대상 액터
	FName m_SocketName;// 소켓
	FVector m_Offset;// Offset
	float m_fInitVelocity;// 초기 속도
	float m_fFinalVelocity;// 최종 속도
	float m_fSec_To_FinalVelocity;// 최종 속도에 도달하는 시간
	float m_fBlendSec;// 블렌딩 시간
};
