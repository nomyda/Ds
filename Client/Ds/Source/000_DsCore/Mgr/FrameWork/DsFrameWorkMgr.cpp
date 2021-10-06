#include "DsFrameWorkMgr.h"

DsFrameWorkMgr::DsFrameWorkMgr()
{

}

void DsFrameWorkMgr::OnNew()
{

}

UWorld* DsFrameWorkMgr::GetWorld()
{
	if (nullptr == GEngine)
		return nullptr;

	const FWorldContext* WorldContext = nullptr;
	for (const FWorldContext& Context : GEngine->GetWorldContexts())
	{
		WorldContext = &Context;
		if (WorldContext->OwningGameInstance == nullptr)
			continue;

		UWorld* pWorld = WorldContext->World();
		if (nullptr == pWorld || false != pWorld->bIsTearingDown)
			continue;
		
		return pWorld;
	}

	return nullptr;
}