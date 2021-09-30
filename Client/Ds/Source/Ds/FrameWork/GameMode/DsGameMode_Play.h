// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "GameFramework/GameModeBase.h"
#include "DsGameMode_Play.generated.h"


class UDSUserWidget;

/**
 * 
 */
UCLASS()
class DS_API ADsGameMode_Play : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADsGameMode_Play(const FObjectInitializer& ObjectInitializer);
	void StartPlay() override;
	APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

public:
	//UDSUserWidget* GetUserWidget() { return m_UserWidget; }

private:
	//UPROPERTY() UDSUserWidget* m_UserWidget;
};
