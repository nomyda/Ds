#include "DsActor.h"
#include "Info/DsActorInfo_Visible.h"
#include "Ctrl/DsActorCtrl_Visible.h"

void DsActor::InitActor(const FDsActorSpawnParam& rParam)
{
	FDsActorInfo_Visible& rInfo_Ue = AddChild<FDsActorInfo_Visible>();
	FDsActorCtrl_Visible& rCtrl_Visible = AddChild<FDsActorCtrl_Visible>();
}

void DsActor::Shutdown()
{
	for (auto pCurCtrl : m_arrCtrl)
	{
		if (nullptr == pCurCtrl)
			continue;

		pCurCtrl->ShutdownCtrl();
	}
	
	m_arrCtrl.Empty();
	m_smapSharedChild.Empty();
}

void DsActor::OnTick(float fDeltaSeconds)
{
	for (auto pCurCtrl : m_arrCtrl)
	{
		if (nullptr == pCurCtrl)
			continue;

		pCurCtrl->TickCtrl(fDeltaSeconds);
	}
}

void DsActor::OnAddChild(const EActor_ChildStructType eType, FDsActor_ChildStruct* pChild)
{
	if (nullptr == pChild || eType != EActor_ChildStructType::Ctrl)
		return;

	FDsActorCtrl_Base* pCtrl = static_cast<FDsActorCtrl_Base*>(pChild);
	pCtrl->InitCtrl(this);
}