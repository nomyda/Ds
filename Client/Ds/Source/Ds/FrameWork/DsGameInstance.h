// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/GameInstance.h"
#include "DsGameInstance.generated.h"

/**
 *
 */
UCLASS()
class DS_API UDsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override;
	void Shutdown() override;
};
