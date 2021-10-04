// Fill out your copyright notice in the Description page of Project Settings.


#include "DsGameInstance.h"
#include "Mgr/IMgr.h"



void UDsGameInstance::Init()
{
	Super::Init();
	IMgr::InitM();
}

void UDsGameInstance::Shutdown()
{
	IMgr::ShutdownM();
	Super::Shutdown();
}
