#pragma once
#include "Containers/SortedMap.h"

enum class EMgr_Index : int16
{
	ClientVariable,
	Actor,
	Max,
};

class DSCORE_API IMgr
{
public:
	virtual ~IMgr() {}
	virtual EMgr_Index GetIndex() const = 0;

public:
	static void InitM();
	static void ShutdownM();

protected:
	static void AddM(const EMgr_Index Index, IMgr& pMgr);
	static bool TickMgr(float fDeltaSeconds);

	virtual void OnInit() {}
	virtual void OnShutdown() {}
	virtual void OnTick(float fDeltaSeconds) {}

private:
	static IMgr* ms_arrMgr[EMgr_Index::Max];
	static FDelegateHandle ms_dgTickHandle;
};