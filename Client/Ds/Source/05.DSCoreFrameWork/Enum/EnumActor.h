#pragma once

enum class EAttribute : int8
{
	EMaxHP,				// �ִ� ü��
	ECurHP,				// ���� ü��
	ERegainHP,			// ü�� ���
	EMaxStamina,		// �ִ� ���¹̳�
	ECurStamina,		// ���� ���¹̳�
	ERegainStamina,		// ���¹̳� ���
	EAttackDamage,		// ���� ������
	EAttackSpeed,		// ���� �ӵ�
	EHitRate,			// ���� Ȯ��
	EDodgeRate,			// ȸ�� Ȯ��
	ECriticalRate,		// ũ��Ƽ�� Ȯ��
	EDefence,			// ����
	EMoveSpeed,			// �̵� �ӵ�
	ESightRange,		// �þ� ����
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