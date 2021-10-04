#pragma once
#include "Containers/SortedMap.h"

enum class EMgr_Index : int16
{
	Log,
	ClientVariable,
	Actor,
	Max,
};

struct FDsClassMsg_InitGame;
struct FDsClassMsg_ShutdownGame;

class DSCORE_API IMgr
{
public:
	IMgr();
	virtual ~IMgr() {}
	virtual EMgr_Index GetIndex() const = 0;
	
	static void InitM();
	static void ShutdownM();

protected:
	static void AddM(const EMgr_Index Index, IMgr& pMgr);
	static void RemoveM(const EMgr_Index Index);

	virtual void OnInit() {}
	virtual void OnShutdown() {}
	virtual void OnTick(float fDeltaSeconds) {}


private:
	static bool TickMgr(float fDeltaSeconds);


private:
	static IMgr* ms_arrMgr[EMgr_Index::Max];
	static FDelegateHandle ms_dgTickHandle;
};