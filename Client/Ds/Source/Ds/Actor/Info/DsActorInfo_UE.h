#pragma once
#include "Actor/DsActorInfo_Base.h"
#include "DsActorInfo_UE.generated.h"

USTRUCT()
struct FDsActorInfo_UE : public FDsActorInfo_Base
{
	GENERATED_BODY()

public:
	int32 iTest;
};