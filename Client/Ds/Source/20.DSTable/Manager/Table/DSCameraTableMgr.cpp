#include "DSCameraTableMgr.h"
#include "Table/Camera/DSCameraTable.h"

EMgrIndex DSCameraTableM::GetIndex() const
{
	return EMgrIndex::TableMgr_Camera;
}

void DSCameraTableM::OnInit()
{
	AddDataTablePathToLoad(TEXT("DataTable'/Game/Table/Camera/CameraTable.CameraTable'"));
	RequestAsyncLoading();
}
