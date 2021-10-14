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
	if (m_ActorTid.IsNone())
		return;

	InitUeActor(m_ActorTid);
}

void ADsUePawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ADsUePawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ADsUePawn::InitUeActor(const FName& ActorTid)
{
}
