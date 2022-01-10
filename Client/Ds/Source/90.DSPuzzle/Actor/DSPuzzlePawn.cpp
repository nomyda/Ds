// Copyright Epic Games, Inc. All Rights Reserved.

#include "DSPuzzlePawn.h"
#include "DSPuzzleBlock.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

ADSPuzzlePawn::ADSPuzzlePawn(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ADSPuzzlePawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UCameraComponent* OurCamera = PC->GetViewTarget()->FindComponentByClass<UCameraComponent>())
			{
				FVector Start = OurCamera->GetComponentLocation();
				FVector End = Start + (OurCamera->GetComponentRotation().Vector() * 8000.0f);
				TraceForBlock(Start, End, true);
			}
		}
		else
		{
			FVector Start, Dir, End;
			PC->DeprojectMousePositionToWorld(Start, Dir);
			End = Start + (Dir * 8000.0f);
			TraceForBlock(Start, End, false);
		}
	}
}

void ADSPuzzlePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("ResetVR", EInputEvent::IE_Pressed, this, &ADSPuzzlePawn::OnResetVR);
	PlayerInputComponent->BindAction("TriggerClick", EInputEvent::IE_Pressed, this, &ADSPuzzlePawn::TriggerClick);
}

void ADSPuzzlePawn::CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult)
{
	Super::CalcCamera(DeltaTime, OutResult);

	OutResult.Rotation = FRotator(-90.0f, -90.0f, 0.0f);
}

void ADSPuzzlePawn::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ADSPuzzlePawn::TriggerClick()
{
	if (CurrentBlockFocus)
	{
		CurrentBlockFocus->HandleClicked();
	}
}

void ADSPuzzlePawn::TraceForBlock(const FVector& Start, const FVector& End, bool bDrawDebugHelpers)
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	if (bDrawDebugHelpers)
	{
		DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Red);
		DrawDebugSolidBox(GetWorld(), HitResult.Location, FVector(20.0f), FColor::Red);
	}
	//if (HitResult.GetHitObjectHandle().IsValid())
	//{
	//	if (HitResult.GetHitObjectHandle() != CurrentBlockFocus)
	//	{
	//		if (CurrentBlockFocus)
	//		{
	//			CurrentBlockFocus->Highlight(false);
	//		}
	//		ADSPuzzleBlock* HitBlock = HitResult.GetHitObjectHandle().FetchActor<ADSPuzzleBlock>();
	//		if (HitBlock)
	//		{
	//			HitBlock->Highlight(true);
	//		}
	//		CurrentBlockFocus = HitBlock;
	//	}
	//}
	//else if (CurrentBlockFocus)
	//{
	//	CurrentBlockFocus->Highlight(false);
	//	CurrentBlockFocus = nullptr;
	//}
}