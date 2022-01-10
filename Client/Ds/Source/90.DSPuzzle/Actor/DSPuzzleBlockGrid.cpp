// Copyright Epic Games, Inc. All Rights Reserved.

#include "DSPuzzleBlockGrid.h"
#include "DSPuzzleBlock.h"
#include "Components/TextRenderComponent.h"
#include "Manager/Timer/DSTimerMgr.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

ADSPuzzleBlockGrid::ADSPuzzleBlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);

	// Set defaults
	//Size = 3;
	BlockSpacing = 300.f;
	Num_Width = 3;
	Num_Height = 5;
}


void ADSPuzzleBlockGrid::BeginPlay()
{
	Super::BeginPlay();


	Preparation();
}


void ADSPuzzleBlockGrid::AddScore()
{
	// Increment score
	Score++;

	// Update text
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

void ADSPuzzleBlockGrid::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (nullptr == PropertyChangedEvent.Property)
		return;

	if (PropertyChangedEvent.Property->GetFName() != GET_MEMBER_NAME_CHECKED(ADSPuzzleBlockGrid, Num_Width) &&
		PropertyChangedEvent.Property->GetFName() != GET_MEMBER_NAME_CHECKED(ADSPuzzleBlockGrid, Num_Height) &&
		PropertyChangedEvent.Property->GetFName() != GET_MEMBER_NAME_CHECKED(ADSPuzzleBlockGrid, Array_BlockInfo) &&
		PropertyChangedEvent.Property->GetFName() != GET_MEMBER_NAME_CHECKED(FDSPuzzleBlockInfo, BlockType))
		return;

	Preparation();
}

void ADSPuzzleBlockGrid::Preparation()
{
	const int32 iMaxArrayIndex = Num_Width * Num_Height;
	Array_BlockInfo.SetNum(iMaxArrayIndex);
	m_iCurBlockIndex = -1;
	m_StartPoint.Empty();
	m_EndPoint.Empty();
	m_ClosedBlockIndex.Empty();
	for (int32 i = 0; i < iMaxArrayIndex; ++i)
	{
		FDSPuzzleBlockInfo& CurTile = Array_BlockInfo[i];
		if (CurTile.BlockType == EBlockType::StartPoint)
			m_StartPoint.Add(i);
		if (CurTile.BlockType == EBlockType::EndPoint)
			m_EndPoint.Add(i);
	}

	int32 iStartPoint_ArrayIndex = 0;
	int32 iStartArrayIndex_In_Puzzle = 0;
	const int32 iStartPointCount = m_StartPoint.Num();
	if (iStartPointCount > 0)
	{
		iStartPoint_ArrayIndex = FMath::Rand() % iStartPointCount;
		if(iStartPoint_ArrayIndex>= 0 && iStartPoint_ArrayIndex < iStartPointCount)
			iStartArrayIndex_In_Puzzle = m_StartPoint[iStartPoint_ArrayIndex];
	}


	m_iCurBlockIndex = iStartArrayIndex_In_Puzzle;
	m_ClosedBlockIndex.Add(m_iCurBlockIndex);


	// Number of blocks
	const int32 NumBlocks = Num_Width * Num_Height;
	for (int32 iRemoveIndex = m_ArrayPuzzleBlockPtr.Num()-1; iRemoveIndex >= NumBlocks; --iRemoveIndex)
	{
		ADSPuzzleBlock* pCurBlock = m_ArrayPuzzleBlockPtr[iRemoveIndex];
		if (nullptr == pCurBlock || false == pCurBlock->IsValidLowLevel() || pCurBlock->IsPendingKill())
		{
			m_ArrayPuzzleBlockPtr[iRemoveIndex] = nullptr;
			continue;
		}

		pCurBlock->Destroy();
		m_ArrayPuzzleBlockPtr[iRemoveIndex] = nullptr;
	}

	// Loop to spawn each block
	m_ArrayPuzzleBlockPtr.SetNum(NumBlocks);
	for (int32 BlockIndex = 0; BlockIndex < NumBlocks; BlockIndex++)
	{
		FDSPuzzleBlockInfo& rBlockInfo = Array_BlockInfo[BlockIndex];

		const float XOffset = (BlockIndex / Num_Width) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex % Num_Width) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		ADSPuzzleBlock* NewBlock = m_ArrayPuzzleBlockPtr[BlockIndex];
		if (nullptr == NewBlock)
		{
			NewBlock = GetWorld()->SpawnActor<ADSPuzzleBlock>(BlockLocation, FRotator(0, 0, 0));
			m_ArrayPuzzleBlockPtr[BlockIndex] = NewBlock;
		}
		else
			NewBlock->SetActorLocationAndRotation(BlockLocation, FRotator(0, 0, 0));

		// Tell the block about its owner
		if (nullptr == NewBlock)
			continue;

		NewBlock->OwningGrid = this;
		int32 ColorType = static_cast<int32>(rBlockInfo.BlockType);
		if (ColorType < 0 || ColorType >= static_cast<int32>(EBlockType::Max))
			ColorType = 0;

		const FVector& BlockColor = Color_Of_BlockType[ColorType];
		NewBlock->ChangeColor(BlockColor);
	}
}

bool ADSPuzzleBlockGrid::FindNextBlock(int32& iOutNextTileIndex, float& fSecToStartMoving) const
{
	if (false == IsValid_BlockIndex(m_iCurBlockIndex))
		return false;

	FDSPuzzleBlockInfo kNeighborTile;
	for (int32 iDirection = static_cast<int32>(EDirectionOfMove::DownSide); iDirection > static_cast<int32>(EDirectionOfMove::TopSide); --iDirection)
	{
		const EDirectionOfMove eDirection = static_cast<EDirectionOfMove>(iDirection);
		const int32 iNeighborTileIndex = GetNeighborBlock(eDirection, kNeighborTile);
		if (iNeighborTileIndex < 0)
			continue;

		if (false == IsPossibleToMove(eDirection, iNeighborTileIndex, kNeighborTile))
			continue;

		iOutNextTileIndex = iNeighborTileIndex;
		fSecToStartMoving = DSTimerMgr::GetRealTimeSeconds();
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, FString::Printf(TEXT("%d => %d")
			, m_iCurBlockIndex, iOutNextTileIndex), true, FVector2D(2.0f));
		return true;
	}

	return false;
}

int32 ADSPuzzleBlockGrid::GetNeighborBlock(const EDirectionOfMove eDirection, FDSPuzzleBlockInfo& rOutPuzzleTile) const
{
	if (EDirectionOfMove::Max == eDirection)
	{
		return -1;
	}

	int32 iCurX, iCurY;
	if (false == GetXY_By_BlockIndex(m_iCurBlockIndex, iCurX, iCurY))
		return -1;

	int32 iNeighborX = iCurX;
	int32 iNeighborY = iCurY;
	switch (eDirection)
	{
	case EDirectionOfMove::TopSide:
	{
		iNeighborY = iCurY - 1;
		break;
	}
	case EDirectionOfMove::LeftSide:
	{
		iNeighborX = iCurX - 1;
		break;
	}
	case EDirectionOfMove::RightSide:
	{
		iNeighborX = iCurX + 1;
		break;
	}
	case EDirectionOfMove::DownSide:
	{
		iNeighborY = iCurY + 1;
		break;
	}
	default:
	{
		return -1;
	}
	}


	const int32 iNeighborTileIndex = GetBlockIndex_By_XY(iNeighborX, iNeighborY);
	if (false == IsValid_BlockIndex(iNeighborTileIndex))
		return -1;

	rOutPuzzleTile = Array_BlockInfo[iNeighborTileIndex];
	return iNeighborTileIndex;
}

bool ADSPuzzleBlockGrid::IsPossibleToMove(const EDirectionOfMove eDirection, const int32 iNeighborTileIndex, const FDSPuzzleBlockInfo& rNeighborTile) const
{
	if (false == IsValid_BlockIndex(m_iCurBlockIndex) || false == IsValid_BlockIndex(iNeighborTileIndex))
		return false;

	if (m_ClosedBlockIndex.Contains(iNeighborTileIndex))
		return false;

	const FDSPuzzleBlockInfo& rCurTile = Array_BlockInfo[m_iCurBlockIndex];
	if (0 == rCurTile.BlockShape)
		return false;

	const int32 iFromValue = 1 << static_cast<int32>(eDirection);
	const bool bPossible_From = rCurTile.BlockShape & iFromValue;
	if (false == bPossible_From)
		return false;

	const EDirectionOfMove eDirection_To = static_cast<EDirectionOfMove>(static_cast<int32>(EDirectionOfMove::Max) - static_cast<int32>(eDirection) - 1);
	const int32 iToValue = 1 << static_cast<int32>(eDirection_To);
	const bool bPossible_To = rNeighborTile.BlockShape & iToValue;
	return bPossible_To;
}

bool ADSPuzzleBlockGrid::IsNeighborBlock(const int32 LTileIndex, const int32 RTileIndex) const
{
	if (LTileIndex == RTileIndex)
		return false;

	int32 iLX, iLY, iRX, iRY;
	if (false == GetXY_By_BlockIndex(LTileIndex, iLX, iLY) ||
		false == GetXY_By_BlockIndex(RTileIndex, iRX, iRY))
		return false;

	bool bSameX = (iLX == iRX);
	bool bSameY = (iLY == iRY);
	if (false == bSameX && false == bSameY)
		return false;

	bool bNeighborX = (FMath::Abs(iLX - iRX) == 1);
	bool bNeighborY = (FMath::Abs(iLY - iRY) == 1);
	return (bSameX && bNeighborY) || (bSameY && bNeighborX);
}

bool ADSPuzzleBlockGrid::IsValid_BlockIndex(const int32 BlockArrayIndex) const
{
	const int32 iMaxArrayIndex = Num_Width * Num_Height;
	if (BlockArrayIndex < 0 || BlockArrayIndex >= Array_BlockInfo.Num() || BlockArrayIndex >= iMaxArrayIndex)
		return false;

	return true;
}

bool ADSPuzzleBlockGrid::GetXY_By_BlockIndex(const int32 BlockArrayIndex, int32& iOutX, int32& iOutY) const
{
	if (false == IsValid_BlockIndex(BlockArrayIndex))
		return false;

	iOutX = BlockArrayIndex % Num_Width;
	iOutY = BlockArrayIndex / Num_Width;
	if (iOutY >= Num_Height)
		return false;

	return true;
}

int32 ADSPuzzleBlockGrid::GetBlockIndex_By_XY(const int32 iX, const int32 iY) const
{
	if (iX < 0 || iY < 0)
		return -1;

	const int32 iCurTileIndex = iY * Num_Width + iX;
	if (false == IsValid_BlockIndex(iCurTileIndex))
		return -1;

	return iCurTileIndex;
}

void ADSPuzzleBlockGrid::UpdateMove()
{
	if (m_iNextBlockIndex < 0)
		return;

	// 이동중일때 
	float fCurSec = DSTimerMgr::GetRealTimeSeconds();
	float fPassedSec = fCurSec - m_fSecToStartMoving;
	if (fPassedSec < SecToGoFromBlockToBlock || false == IsNeighborBlock(m_iCurBlockIndex, m_iNextBlockIndex))
		return;

	// 목적지에 도착했을대 처리
	m_ClosedBlockIndex.Add(m_iCurBlockIndex);
	m_iCurBlockIndex = m_iNextBlockIndex;

	// 최종 목적지에 도착했다면 성공 처리
	if (CheckArrive_FinalDestination())
	{
		return;
	}

	// 다음 목적지 검색
	if (FindNextBlock(m_iNextBlockIndex, m_fSecToStartMoving))
		return;

	// 이동할수 없을때 실패 처리
	OnMoveFail();
}

void ADSPuzzleBlockGrid::OnMoveFail()
{
	m_iNextBlockIndex = -1;
	m_fSecToStartMoving = 0.0f;
	GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red
		, FString::Printf(TEXT("Nowhere to go : %d"), m_iCurBlockIndex)
		, true, FVector2D(2.0f));
}

bool ADSPuzzleBlockGrid::CheckArrive_FinalDestination()
{
	if (false == m_EndPoint.Contains(m_iCurBlockIndex))
	{
		return false;
	}

	m_iNextBlockIndex = -1;
	m_fSecToStartMoving = 0.0f;
	GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red
		, FString::Printf(TEXT("Arriving at the destination : %d"), m_iCurBlockIndex)
		, true, FVector2D(2.0f));
	return true;
}

void ADSPuzzleBlockGrid::BeginPuzzle()
{

}

#undef LOCTEXT_NAMESPACE
