#pragma once
#include "DsActorInfo_Base.h"
#include "DsActorCtrl_Base.h"
#include "Helper/DsHelper_Struct.h"
#include "Message/DsClassMsg_Log.h"

struct FDsActorSpawnParam;
class DsActor
{
public:
	DsActor(const int32 iGuid) : m_iGuid(iGuid) {}
	void InitActor(const FDsActorSpawnParam& rParam);

	template<class CtrlClass>
	CtrlClass& Get_Or_AddCtrl();

	template<class CtrlClass>
	const CtrlClass* GetCtrl();

	template<class InfoClass>
	InfoClass& Get_Or_AddInfo();

	template<class InfoClass>
	const InfoClass* GetInfo();

private:
	int32 m_iGuid;
	typedef TSharedPtr<FDsActorInfo_Base> SharedInfo;
	typedef TSharedPtr<FDsActorCtrl_Base> SharedCtrl;
	TSortedMap<const UScriptStruct*, SharedInfo> m_smapSharedInfo;
	TSortedMap<const UScriptStruct*, SharedCtrl> m_smapSharedCtrl;
};


#include "DsActor.hpp"