#pragma once
#include "UObject/Interface.h"
#include "IDsUeActorInterface.generated.h"

UINTERFACE(MinimalAPI)
class UDsUeActorInterface : public UInterface
{
	GENERATED_BODY()
};

class IDsUeActorInterface
{
	GENERATED_BODY()

public:	
	virtual void InitUeActor(const FName& m_ActorTid) = 0;
	virtual void ShutdownUeActor() = 0;
};