#pragma once
#include "DSPuzzleBlockInfo.generated.h"

UENUM()
enum class EBlockType : int16
{
	Fix,
	Rotatable,
	StartPoint,
	EndPoint,
	Max,
};

enum class EDirectionOfMove : int16
{
	TopSide,
	LeftSide,
	RightSide,
	DownSide,
	Max,
};

static const float SecToGoFromBlockToBlock = 3.0f;	// Ÿ�Ͽ��� Ÿ�ϰ� �̵��ϴµ� �ɸ��� �ð�
static FVector Color_Of_BlockType[static_cast<int32>(EBlockType::Max)] = {
	FVector(0.3, 0.3, 0.3),		// Fix,
	FVector(0.0, 1.0, 0.25),	// Rotatable,
	FVector(0.5, 1.0, 1.0),		// StartPoint
	FVector(1.0, 1.0, 0.0) };	// EndPoint,


USTRUCT()
struct FDSPuzzleBlockInfo
{
	GENERATED_BODY()

public:
	FDSPuzzleBlockInfo();
	~FDSPuzzleBlockInfo();

	UPROPERTY(Category = Info, EditAnywhere) uint32 BlockShape;
	UPROPERTY(Category = Info, EditAnywhere) EBlockType BlockType;
};

