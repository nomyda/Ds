#pragma once
#include "UObject/Interface.h"
#include "DSActorInterface.generated.h"

UINTERFACE(MinimalAPI)
class UDSActorInterface : public UInterface
{
	GENERATED_BODY()
};

class IDSActorInterface
{
	GENERATED_BODY()

public:
	virtual void Move(const int MoveDirectionBit) {}

protected:
	//virtual bool InitActor() = 0;
};