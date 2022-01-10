// Copyright Epic Games, Inc. All Rights Reserved.

#include "DSPuzzleGameMode.h"
#include "Controller/DSPuzzlePlayerController.h"
#include "Actor/DSPuzzlePawn.h"

ADSPuzzleGameMode::ADSPuzzleGameMode()
{
	// no pawn by default
	DefaultPawnClass = ADSPuzzlePawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = ADSPuzzlePlayerController::StaticClass();
}
