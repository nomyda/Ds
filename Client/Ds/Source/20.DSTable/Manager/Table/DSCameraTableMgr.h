#pragma once
#include "TTableMgr.h"

struct FDSCameraTable;
class DSTABLE_API DSCameraTableM : public TTableM<FDSCameraTable, DSCameraTableM>
{
public:
	EMgrIndex GetIndex() const override;
	void OnInit() override;
};