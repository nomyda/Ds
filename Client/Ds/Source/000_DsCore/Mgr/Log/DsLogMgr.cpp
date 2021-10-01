#include "DsLogMgr.h"
#include "Message/DsClassMsg_Log.h"

DsLogMgr::DsLogMgr()
{

}

EMgr_Index DsLogMgr::GetIndex() const
{
	return EMgr_Index::Log;
}

void DsLogMgr::OnInit()
{
	m_hOnLog = FDsClassMsg_Log::OnClassMsg().AddRaw(this, &DsLogMgr::OnClassMessage);
}

void DsLogMgr::OnClassMessage(const FDsClassMsg_Log& rLog)
{

}