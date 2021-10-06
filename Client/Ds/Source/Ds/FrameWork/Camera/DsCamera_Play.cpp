// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameWork/Camera/DsCamera_Play.h"

// Sets default values
ADsCamera_Play::ADsCamera_Play()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADsCamera_Play::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADsCamera_Play::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADsCamera_Play::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

