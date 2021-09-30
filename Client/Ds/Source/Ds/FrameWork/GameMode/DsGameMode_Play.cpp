// Copyright Epic Games, Inc. All Rights Reserved.


#include "DsGameMode_Play.h"
#include "FrameWork/Controller/DsController_Play.h"

ADsGameMode_Play::ADsGameMode_Play(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//DefaultPawnClass = ADSPawn_CameraTarget::StaticClass();
	PlayerControllerClass = ADsPlayerController_Play::StaticClass();
}

void ADsGameMode_Play::StartPlay()
{
	Super::StartPlay();
}

APlayerController* ADsGameMode_Play::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}