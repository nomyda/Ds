// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Info/DSPuzzleBlockInfo.h"
#include "Actor/DSPuzzleBlock.h"
#include "DSPuzzleBlockGrid.generated.h"

/** Class used to spawn blocks and manage score */
UCLASS()
class DSPUZZLE_API ADSPuzzleBlockGrid : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** Text component for the score */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* ScoreText;

public:
	ADSPuzzleBlockGrid();

	/** How many blocks have been clicked */
	int32 Score;

	/** Spacing of blocks */
	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	float BlockSpacing;

protected:
	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

public:

	/** Handle the block being clicked */
	void AddScore();

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns ScoreText subobject **/
	FORCEINLINE class UTextRenderComponent* GetScoreText() const { return ScoreText; }

private:
	UPROPERTY(Category = Info, EditAnywhere) int32 Num_Width;
	UPROPERTY(Category = Info, EditAnywhere) int32 Num_Height;
	UPROPERTY(Category = Info, EditAnywhere) TArray<FDSPuzzleBlockInfo> Array_BlockInfo;
	UPROPERTY() TArray<ADSPuzzleBlock*> m_ArrayPuzzleBlockPtr;
	TArray<int32> m_StartPoint;
	TArray<int32> m_EndPoint;
	TArray<int32> m_ClosedBlockIndex;
	int32 m_iCurBlockIndex;
	int32 m_iNextBlockIndex;
	float m_fSecToStartMoving;

private:
#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	void Preparation();
	bool FindNextBlock(int32& iOutNextTileIndex, float& fSecToStartMoving) const;
	int32 GetNeighborBlock(const EDirectionOfMove eDirection, FDSPuzzleBlockInfo& rOutPuzzleTile) const;
	bool IsPossibleToMove(const EDirectionOfMove eDirection, const int32 iNeighborTileIndex, const FDSPuzzleBlockInfo& rNeighborTile) const;
	bool IsNeighborBlock(const int32 LTileIndex, const int32 RTileIndex) const;
	bool IsValid_BlockIndex(const int32 BlockArrayIndex) const;
	bool GetXY_By_BlockIndex(const int32 BlockArrayIndex, int32& iOutX, int32& iOutY) const;
	int32 GetBlockIndex_By_XY(const int32 iX, const int32 iY) const;
	void UpdateMove();
	void OnMoveFail();
	bool CheckArrive_FinalDestination();

	void BeginPuzzle();
};



