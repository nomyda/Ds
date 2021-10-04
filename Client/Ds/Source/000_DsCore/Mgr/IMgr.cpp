#include "IMgr.h"
#include "Containers/Ticker.h"
#include "Message/DsClassMsg_InitGame.h"

/*[작업]
* 매니저간 매시지 전송
*/
IMgr* IMgr::ms_arrMgr[] = {nullptr,};
FDelegateHandle IMgr::ms_dgTickHandle;

IMgr::IMgr()
{
}

void IMgr::InitM()
{
	FDsClassMsg_InitGame kInitGame;
	kInitGame.Send();

	for (int32 iIndex = 0; iIndex < static_cast<int32>(EMgr_Index::Max); ++iIndex)
	{
		if (nullptr == ms_arrMgr[iIndex])
			continue;

		ms_arrMgr[iIndex]->OnInit();
	}

	ms_dgTickHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateStatic(&IMgr::TickMgr));
}

void IMgr::ShutdownM()
{
	FTicker::GetCoreTicker().RemoveTicker(ms_dgTickHandle);
	for (int32 iIndex = 0; iIndex < static_cast<int32>(EMgr_Index::Max); ++iIndex)
	{
		if (nullptr == ms_arrMgr[iIndex])
			continue;

		ms_arrMgr[iIndex]->OnShutdown();
		ms_arrMgr[iIndex] = nullptr;
	}
}

void IMgr::AddM(const EMgr_Index Index, IMgr& pMgr)
{
	if (Index == EMgr_Index::Max)
		return;

	if (ms_arrMgr[static_cast<int32>(Index)])
		return;

	ms_arrMgr[static_cast<int32>(Index)] = &pMgr;
}

void IMgr::RemoveM(const EMgr_Index Index)
{
	if (Index == EMgr_Index::Max)
		return;

	ms_arrMgr[static_cast<int32>(Index)] = nullptr;
}

bool IMgr::TickMgr(float fDeltaSeconds)
{
	for (auto& pCurPair : ms_arrMgr)
	{
		if (nullptr == pCurPair)
			continue;

		pCurPair->OnTick(fDeltaSeconds);
	}

	return true;
}