#pragma once
#include "Singleton/DsSingleton_SharedPtr.h"

class DSCORE_API DsFrameWorkMgr : public DsSingleton_SharedPtr<DsFrameWorkMgr>
{
public:
	DsFrameWorkMgr();
	void OnNew() override;

	UWorld* GetWorld();
};
