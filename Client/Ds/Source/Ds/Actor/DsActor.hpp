#pragma once

template<class ChildStruct>
bool DsActor::HasChild() const
{
	const UScriptStruct* pTargetStruct = ChildStruct::StaticStruct();
	return m_smapSharedChild.Contains(pTargetStruct);
}

template<class ChildStruct, class... ArgTypes>
ChildStruct& DsActor::AddChild(ArgTypes&&... args)
{
	if (HasChild<ChildStruct>())
		return const_cast<ChildStruct&>(*GetChild<ChildStruct>());
	
	ChildStruct* pChild = new ChildStruct(Forward<ArgTypes>(args)...);
	if (nullptr == pChild)
	{
		DsLog(TEXT("actor"), ELogVerbosity::Warning, TEXT("false == new ChildStruct"));
	}

	SharedChild spChild = SharedChild(pChild);
	const UScriptStruct* pTargetStruct = ChildStruct::StaticStruct();
	m_smapSharedChild.Add(pTargetStruct, spChild);

	const EActor_ChildStructType eType = GetChildStructType<ChildStruct>();
	OnAddChild(eType, pChild);
	return *pChild;
}

template<class ChildStruct>
ChildStruct& DsActor::Get_Or_AddChild()
{
	return AddChild<ChildStruct>();
}

template<class ChildStruct>
const ChildStruct* DsActor::GetChild()
{
	if (HasChild<ChildStruct>())
	{
		const UScriptStruct* pTargetStruct = ChildStruct::StaticStruct();
		auto& rspChild = m_smapSharedChild[pTargetStruct];
		return static_cast<const ChildStruct*>(rspChild.Get());
	}

	return nullptr;
}

template<class ChildStruct>
EActor_ChildStructType DsActor::GetChildStructType()
{
	const UScriptStruct* pBaseCtrlStruct = FDsActorCtrl_Base::StaticStruct();
	const UScriptStruct* pBaseInfoStruct = FDsActorInfo_Base::StaticStruct();
	const UScriptStruct* pChildStruct = ChildStruct::StaticStruct();
	if (DsHelper_Struct::IsCastEnable(pBaseCtrlStruct, pChildStruct))
		return EActor_ChildStructType::Ctrl;

	if (DsHelper_Struct::IsCastEnable(pBaseInfoStruct, pChildStruct))
		return EActor_ChildStructType::Info;

	return EActor_ChildStructType::Max;
}
