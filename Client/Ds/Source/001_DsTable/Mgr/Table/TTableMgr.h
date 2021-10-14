#pragma once
#include "DsTableMgr_Base.h"
#include "Manager/TMgr.h"


template<class UnrealTableStruct, class TableManagerClass>
class TTableM : public DsTableMgr_Base, public TMgr<TableManagerClass>
{
public:
	typedef TDelegate<void(const UnrealTableStruct*)> TDelegate_GetTable;
	void GetTable(const FName& Tid, TDelegate_GetTable dgGetTable);
	UnrealTableStruct* GetTable(const FName& Tid, const bool bLoad = false);

protected:
	void OnTick(float fDeltaSeconds) override;

private:
	TSortedMap<FName, TDelegate_GetTable, FDefaultAllocator, FNameFastLess> m_smTid_And_Delegate;
};


#include "TTableMgr.hpp"