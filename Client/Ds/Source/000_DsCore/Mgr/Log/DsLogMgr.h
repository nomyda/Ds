#pragma once
#include "Mgr/TMgr.h"

struct FDsClassMsg_Log;
class DSCORE_API DsLogMgr : public TMgr<DsLogMgr>
{
public:
	DsLogMgr();
	EMgr_Index GetIndex() const override;

	void OnInit() override;

private:
	void OnClassMessage(const FDsClassMsg_Log& rLog);

private:
	FDelegateHandle m_hOnLog;
};
