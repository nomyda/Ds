#pragma once
#include "Singleton/DsSingleton_Static.h"
#include "Message/DsClassMsg_Log.h"

struct FDsClassMsg_Log;
class DSCORE_API DsLogMgr : public DsSingleton_Static<DsLogMgr>
{
public:
	DsLogMgr()
	{
		m_hOnLog = FDsClassMsg_Log::GetDelegate().AddRaw(this, &DsLogMgr::OnClassMessage);
	}

private:
	void OnClassMessage(const FDsClassMsg_Log& rLog);

private:
	FDelegateHandle m_hOnLog;
};
