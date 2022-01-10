// Fill out your copyright notice in the Description page of Project Settings.


#include "DSGameInstance.h"
#include "Manager/Ue4/DSUe4Mgr.h"
#include "Manager/IMgr.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif


void UDSGameInstance::Init()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int32* p = DBG_NEW int32;
	Super::Init();
	DSUe4Mgr::Get().SetGameInstance(this);
	IMgr::InitMgr();
}

void UDSGameInstance::Shutdown()
{
	Super::Shutdown();
	IMgr::ShutdownMgr();
	DSUe4Mgr::Get().SetGameInstance(nullptr);
	_CrtDumpMemoryLeaks();
}