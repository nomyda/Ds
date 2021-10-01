#pragma once

template<class CtrlClass>
CtrlClass& DsActor::Get_Or_AddCtrl()
{
	const CtrlClass* pCtrl = GetCtrl<CtrlClass>();
	if (pCtrl)
		return const_cast<CtrlClass&>(*pCtrl);

	const UScriptStruct* pTargetStruct = CtrlClass::StaticStruct();
	const UScriptStruct* pBaseStruct = FDsActorCtrl_Base::StaticStruct();
	if (false == DsHelper_Struct::IsCastEnable(pBaseStruct, pTargetStruct))
	{
		FDsClassMsg_Log kLog(TEXT("false == IsCastEnable, Caller = %s"), *FString(__FUNCTION__));
		kLog.Send();
		static CtrlClass kErrorCtrl;
		return kErrorCtrl;
	}
	
	SharedCtrl spCtrl = SharedCtrl(new CtrlClass);
	m_smapSharedCtrl.Add(pTargetStruct, spCtrl);
	return static_cast<CtrlClass&>(*spCtrl.Get());

}

template<class CtrlClass>
const CtrlClass* DsActor::GetCtrl()
{
	const UScriptStruct* pTargetStruct = CtrlClass::StaticStruct();
	if (false == m_smapSharedCtrl.Contains(pTargetStruct))
		return nullptr;

	const UScriptStruct* pBaseStruct = FDsActorCtrl_Base::StaticStruct();
	SharedCtrl& CurCtrl = m_smapSharedCtrl[pTargetStruct];
	if (nullptr == pBaseStruct || false == CurCtrl.IsValid())
		return false;

	if (false == DsHelper_Struct::IsCastEnable(pBaseStruct, pTargetStruct))
		return false;

	return static_cast<CtrlClass*>(CurCtrl.Get());
}

template<class InfoClass>
InfoClass& DsActor::Get_Or_AddInfo()
{
	const InfoClass* pInfo = GetInfo<InfoClass>();
	if (pInfo)
		return const_cast<InfoClass&>(*pInfo);

	const UScriptStruct* pTargetStruct = InfoClass::StaticStruct();
	const UScriptStruct* pBaseStruct = FDsActorInfo_Base::StaticStruct();
	if (false == DsHelper_Struct::IsCastEnable(pBaseStruct, pTargetStruct))
	{
		FDsClassMsg_Log kLog(TEXT("false == IsCastEnable"));
		kLog.Send();
		static InfoClass kErrorInfo;
		return kErrorInfo;
	}

	SharedInfo spInfo = SharedInfo(new InfoClass);
	m_smapSharedInfo.Add(pTargetStruct, spInfo);
	return static_cast<InfoClass&>(*spInfo.Get());
}

template<class InfoClass>
const InfoClass* DsActor::GetInfo()
{
	const UScriptStruct* pTargetStruct = InfoClass::StaticStruct();
	if (false == m_smapSharedInfo.Contains(pTargetStruct))
		return nullptr;

	const UScriptStruct* pBaseStruct = FDsActorInfo_Base::StaticStruct();
	SharedInfo& CurInfo = m_smapSharedInfo[pTargetStruct];
	if (nullptr == pBaseStruct || false == CurInfo.IsValid())
		return false;

	if (false == DsHelper_Struct::IsCastEnable(pBaseStruct, pTargetStruct))
		return false;

	return static_cast<InfoClass*>(CurInfo.Get());
}
