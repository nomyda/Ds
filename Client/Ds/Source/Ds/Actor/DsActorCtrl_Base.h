#pragma once
#include "DsActor_ChildStruct.h"
#include "DsActorCtrl_Base.generated.h"

class DsActor;
USTRUCT()
struct FDsActorCtrl_Base : public FDsActor_ChildStruct
{
	GENERATED_BODY()

public:
	FDsActorCtrl_Base() : m_pParentActor(nullptr) {}
	virtual ~FDsActorCtrl_Base() {}
	virtual void InitCtrl(DsActor* pParentActor) { m_pParentActor = pParentActor; }
	virtual void ShutdownCtrl() {}
	virtual void TickCtrl(float fDeltaSeconds) {}

	DsActor* GetParentActor() { return m_pParentActor; }

protected:
	DsActor* m_pParentActor;
};
