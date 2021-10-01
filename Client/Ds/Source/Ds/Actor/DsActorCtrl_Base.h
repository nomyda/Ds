#pragma once
#include "DsActorCtrl_Base.generated.h"

USTRUCT()
struct FDsActorCtrl_Base
{
	GENERATED_BODY()

public:
	virtual void InitCtrl() {}
	virtual void ShutdownCtrl() {}
	virtual void TickCtrl(float fDeltaSeconds) {}
};
