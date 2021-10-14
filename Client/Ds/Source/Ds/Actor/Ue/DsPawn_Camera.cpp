// Fill out your copyright notice in the Description page of Project Settings.


#include "DsPawn_Camera.h"
#include "Message/DsClassMsg_AttachCamera.h"
#include "Message/DsClassMsg_DetachCamera.h"

// Sets default values
ADsPawn_Camera::ADsPawn_Camera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ADsPawn_Camera::ADsPawn_Camera(const FObjectInitializer& ObjectInitializer)
{

}

// Called when the game starts or when spawned
void ADsPawn_Camera::BeginPlay()
{
	FDsClassMsg_AttachCamera kAttachCamera;
	kAttachCamera.m_TargetPawn = this;
	kAttachCamera.Send();

	Super::BeginPlay();
}

void ADsPawn_Camera::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	FDsClassMsg_DetachCamera kDetachCamera;
	kDetachCamera.m_TargetPawn = this;
	kDetachCamera.Send();

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ADsPawn_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADsPawn_Camera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

