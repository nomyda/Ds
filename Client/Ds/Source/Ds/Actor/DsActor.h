#pragma once
#include "DsActor_ChildStruct.h"
#include "Helper/DsHelper_Struct.h"
#include "Message/DsClassMsg_Log.h"



struct FDsActorCtrl_Base;
struct FDsActorSpawnParam;
class DsActor
{
public:
	DsActor(const int32 iGuid) : m_iGuid(iGuid) {}
	void InitActor(const FDsActorSpawnParam& rParam);
	void Shutdown();
	void OnTick(float fDeltaSeconds);

	template<class ChildStruct>
	bool HasChild() const;

	template<class ChildStruct, class... ArgTypes>
	ChildStruct& AddChild(ArgTypes&&... args);
	void OnAddChild(const EActor_ChildStructType eType, FDsActor_ChildStruct* pChild);

	template<class ChildStruct>
	ChildStruct& Get_Or_AddChild();

	template<class ChildStruct>
	const ChildStruct* GetChild() const;

	template<class ChildStruct>
	ChildStruct* GetChild();

protected:
	template<class ChildStruct>
	static EActor_ChildStructType GetChildStructType();

private:
	int32 m_iGuid;
	typedef TSharedPtr<FDsActor_ChildStruct> SharedChild;
	TSortedMap<const UScriptStruct*, SharedChild> m_smapSharedChild;
	TArray<FDsActorCtrl_Base*> m_arrCtrl;
};


#include "DsActor.hpp"