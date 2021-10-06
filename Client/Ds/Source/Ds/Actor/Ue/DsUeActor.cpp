#include "DsUeActor.h"

ADsUeActor::ADsUeActor()
	: Super()
{

}

ADsUeActor::ADsUeActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

ADsUeActor::~ADsUeActor()
{

}

void ADsUeActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADsUeActor::EndPlay(const EEndPlayReason::Type EndPlayReason) 
{
	Super::EndPlay(EndPlayReason);
}

void ADsUeActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}