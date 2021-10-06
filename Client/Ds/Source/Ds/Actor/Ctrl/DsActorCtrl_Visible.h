#pragma once
#include "Actor/DsActorCtrl_Base.h"
#include "DsActorCtrl_Visible.generated.h"

USTRUCT()
struct FDsActorCtrl_Visible : public FDsActorCtrl_Base
{
	GENERATED_BODY()

public:
	FDsActorCtrl_Visible();

	void InitCtrl(DsActor* pParentActor) override;
};