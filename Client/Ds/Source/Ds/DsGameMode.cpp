// Copyright Epic Games, Inc. All Rights Reserved.

#include "DsGameMode.h"
#include "DsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADsGameMode::ADsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
