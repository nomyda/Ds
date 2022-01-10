#include "DSBuildingTableMgr.h"
#include "Table/Building/DSBuildingTable.h"

EMgrIndex DSBuildingTableM::GetIndex() const
{
	return EMgrIndex::TableMgr_Building;
}

void DSBuildingTableM::OnInit()
{
	AddDataTablePathToLoad(TEXT("DataTable'/Game/Table/Building/BuildingTable.BuildingTable'"));
	RequestAsyncLoading();
}