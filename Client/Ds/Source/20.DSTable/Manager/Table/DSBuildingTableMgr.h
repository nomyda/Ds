#pragma once
#include "Manager/Table/TTableMgr.h"

struct FDSBuildingTable;
class DSTABLE_API DSBuildingTableM : public TTableM<FDSBuildingTable, DSBuildingTableM>
{
public:
	EMgrIndex GetIndex() const override;
	void OnInit() override;
};