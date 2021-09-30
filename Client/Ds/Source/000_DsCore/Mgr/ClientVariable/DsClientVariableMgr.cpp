#include "DsClientVariableMgr.h"


DsClientVariableMgr::DsClientVariableMgr()
{

}

EMgr_Index DsClientVariableMgr::GetIndex() const
{
	return EMgr_Index::ClientVariable;
}

void DsClientVariableMgr::RegistConsolCommand(const TCHAR* FuncKey, const FConsoleCommandWithArgsDelegate& CommandDelegate, const FString& Help)
{
	if (m_smapName_And_ConsoleCommand.Contains(FuncKey))
		return;

	IConsoleCommand* pConsoleCommand = IConsoleManager::Get().RegisterConsoleCommand(FuncKey, *Help, CommandDelegate, ECVF_SetByCommandline);
	if (nullptr == pConsoleCommand)
		return;

	m_smapName_And_ConsoleCommand.Add(FuncKey, pConsoleCommand);
}

void DsClientVariableMgr::UnRegistConsolCommand(const TCHAR* FuncKey)
{
	if (false == m_smapName_And_ConsoleCommand.Contains(FuncKey))
		return;

	m_smapName_And_ConsoleCommand.Remove(FuncKey);
}

//void DsClientVariableMgr::OnInit()
//{
//
//}