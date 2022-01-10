#pragma once

struct DSAttribute
{
public:
	DSAttribute();

public:
	int32 m_MaxHP;
	int32 m_CurHP;
	int32 m_RegainHP;
	int32 m_MaxStamina;
	int32 m_CurStamina;
	int32 m_RegainStamina;
	int32 m_AttackDamage;
	int32 m_AttackSpeed;
	int32 m_HitRate;
	int32 m_DodgeRate;
	int32 m_CriticalRate;
	int32 m_Defence;
	int32 m_MoveSpeed;
	int32 m_SightRange;
};
