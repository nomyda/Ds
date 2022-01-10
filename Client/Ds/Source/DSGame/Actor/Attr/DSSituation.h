#pragma once

struct DSSituation
{
public:
	DSSituation(const FVector& vPos, const float fAngle);

public:
	FVector m_vLocation;
	float m_fAngle;
};