#include "DsUePawn.h"

ADsUePawn::ADsUePawn()
	: Super()
{

}

ADsUePawn::ADsUePawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

ADsUePawn::~ADsUePawn()
{

}

void ADsUePawn::BeginPlay()
{
	Super::BeginPlay();
}

void ADsUePawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ADsUePawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}