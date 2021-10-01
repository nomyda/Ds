#include "DsActor.h"
#include "Info/DsActorInfo_UE.h"
#include "Ctrl/DsActorCtrl_Move.h"

void DsActor::InitActor(const FDsActorSpawnParam& rParam)
{
	FDsActorInfo_UE& rInfo_Ue = Get_Or_AddInfo<FDsActorInfo_UE>();
	FDsActorCtrl_Move& rCtrl_Move = Get_Or_AddCtrl<FDsActorCtrl_Move>();

	const FDsActorInfo_UE* pInfo = GetInfo<FDsActorInfo_UE>();
	const FDsActorCtrl_Move* pCtrl = GetCtrl<FDsActorCtrl_Move>();

	FDsClassMsg_Log kLog(TEXT("DFS"));
	kLog.Send();
}