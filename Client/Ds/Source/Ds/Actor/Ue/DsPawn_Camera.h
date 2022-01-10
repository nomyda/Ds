// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DsPawn_Camera.generated.h"

UCLASS()
class ADsPawn_Camera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADsPawn_Camera();
	ADsPawn_Camera(const FObjectInitializer& ObjectInitializer);

	void Move(const uint32 uiMoveBit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


private:
	void Constructor();

private:
	UPROPERTY(Category=Actor, VisibleAnywhere, DisplayName="Static Mesh", meta=(Tooltim="This static mesh is displayed", AllowPrivateAccess="true"))
		UStaticMeshComponent* m_StaticMesh;
};
