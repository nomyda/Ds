#pragma once
#include "Actor/DsActorInfo_Base.h"
#include "Actor/Ue/IDsUeActorInterface.h"
#include "DsActorInfo_Visible.generated.h"


USTRUCT()
struct FDsActorInfo_Visible : public FDsActorInfo_Base
{
	GENERATED_BODY()

public:
	TWeakPtr<IDsUeActorInterface> m_wpUeActor;
};