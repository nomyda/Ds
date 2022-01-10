#include "DSActorTableM.h"
#include "Table/Actor/DSActorTable.h"
#include "Message/MessageBase.h"

EMgrIndex DSActorTableM::GetIndex() const
{
	return EMgrIndex::TableMgr_Actor;
}

void DSActorTableM::OnInit()
{
	AddDataTablePathToLoad(TEXT("DataTable'/Game/Table/Actor/ActorTable.ActorTable'"));
	RequestAsyncLoading();
	Regist_MessageFunc(FMessage_GameStart::StaticStruct(), &DSActorTableM::Messag);

	FMessageHandler Handler;
	FMessage_GameStart* pMessage = Handler.Get_Or_Add<FMessage_GameStart>();
	IMgr::SendMessage(Handler);
}

void DSActorTableM::Messag(const FMessageHandler& rMessageHandler)
{

}