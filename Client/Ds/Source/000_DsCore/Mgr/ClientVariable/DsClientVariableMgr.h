#pragma once
#include "Mgr/TMgr.h"

class DSCORE_API DsClientVariableMgr : public TMgr<DsClientVariableMgr>
{
public:
	DsClientVariableMgr();
	EMgr_Index GetIndex() const override;
	void RegistConsolCommand(const TCHAR* FuncKey, const FConsoleCommandWithArgsDelegate& CommandDelegate, const FString& Help);
	void UnRegistConsolCommand(const TCHAR* FuncKey);

protected:
	//void OnInit() override;

private:
	TSortedMap<FString, IConsoleCommand*> m_smapName_And_ConsoleCommand;
};

#define Ds_Regist_Console_Command( Command, FuncName, Help ) \
	DsClientVariableMgr::Get().RegistConsolCommand( Command, FConsoleCommandWithArgsDelegate::CreateStatic( FuncName ), Help );