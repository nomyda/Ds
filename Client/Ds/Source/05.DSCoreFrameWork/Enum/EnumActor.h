#pragma once

enum class EAttribute : int8
{
	EMaxHP,				// 최대 체력
	ECurHP,				// 현재 체력
	ERegainHP,			// 체력 재생
	EMaxStamina,		// 최대 스태미너
	ECurStamina,		// 현재 스태미너
	ERegainStamina,		// 스태미너 재생
	EAttackDamage,		// 공격 데미지
	EAttackSpeed,		// 공격 속도
	EHitRate,			// 명중 확률
	EDodgeRate,			// 회피 확률
	ECriticalRate,		// 크리티컬 확률
	EDefence,			// 방어력
	EMoveSpeed,			// 이동 속도
	ESightRange,		// 시야 범위
	Max,
};

enum class EMoveDirection_ArrIndex
{
	Left,
	Right,
	Forward,
	Backward,
	Max,
};

enum class EMoveDirection_BitFlag
{
	None,
	Left = 1 << static_cast<int32>(EMoveDirection_ArrIndex::Left),
	Right = 1 << static_cast<int32>(EMoveDirection_ArrIndex::Right),
	Forward = 1 << static_cast<int32>(EMoveDirection_ArrIndex::Forward),
	Backward = 1 << static_cast<int32>(EMoveDirection_ArrIndex::Backward),
	Max,
};
ENUM_CLASS_FLAGS(EMoveDirection_BitFlag);