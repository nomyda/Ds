#include "IMgr.h"
#include "Containers/Ticker.h"

/*[작업]
* 매니저간 매시지 전송
*/
TSortedMap<EMgrIndex, IMgr*> IMgr::ms_smapMgr;
FDelegateHandle IMgr::ms_dgTickHandle;
TSortedMap<const UScriptStruct*, MessageFunc> IMgr::ms_smapMessageFunc;

void IMgr::AddMgr(const EMgrIndex Index, IMgr* pMgr)
{
	if (ms_smapMgr.Contains(Index) || nullptr == pMgr)
		return;

	ms_smapMgr.Add(Index, pMgr);	
}

void IMgr::InitMgr()
{
	ms_dgTickHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateStatic(&IMgr::TickMgr));
}

void IMgr::ShutdownMgr()
{
	FTicker::GetCoreTicker().RemoveTicker(ms_dgTickHandle);
	for (auto& CurPair : ms_smapMgr)
	{
		if (nullptr == CurPair.Value)
			continue;

		CurPair.Value->OnShutdown();
	}
	ms_smapMgr.Empty();
}

bool IMgr::TickMgr(float fDeltaSeconds)
{
	for (auto& CurPair : ms_smapMgr)
	{
		if (nullptr == CurPair.Value)
			continue;

		CurPair.Value->OnTick(fDeltaSeconds);
	}

	return true;
}

void IMgr::SendMessage(const FMessageHandler& rMessageHandler)
{
	const UScriptStruct* pTargetStruct = rMessageHandler.GetScriptStruct();
	if (nullptr == pTargetStruct)
		return;

	MessageFunc* pFunc = ms_smapMessageFunc.Find(pTargetStruct);
	if (nullptr == pFunc)
		return;

	if (false == (*pFunc))
		return;

	(*pFunc)(rMessageHandler);
}

void IMgr::Regist_MessageFunc(const UScriptStruct* pTargetStruct, MessageFunc Func)
{
	ms_smapMessageFunc.Add(pTargetStruct, Func);
}