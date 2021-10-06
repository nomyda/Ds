#pragma once
#include "DsActor_ChildStruct.h"
#include "DsActorInfo_Base.generated.h"

USTRUCT()
struct FDsActorInfo_Base : public FDsActor_ChildStruct
{
	GENERATED_BODY()

public:
	virtual ~FDsActorInfo_Base() {}
};
