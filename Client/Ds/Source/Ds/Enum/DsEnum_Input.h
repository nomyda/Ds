#pragma once

enum class EInputBitType
{
	Move_Forward = 1,
	Move_Backward = 1 << 1,
	Move_Left = 1 << 2,
	Move_Right = 1 << 3,
	MouseRButton_Pressed = 1 << 4,
	Max,
};