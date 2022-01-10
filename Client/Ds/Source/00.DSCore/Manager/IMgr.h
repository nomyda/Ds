#pragma once
#include "Containers/SortedMap.h"
#include "Message/MessageHandler.h"

enum class EMgrIndex : int16
{
	Ue4,
	ClientVariable,
	Timer,
	AsyncLoading,
	TableMgr_Actor,
	TableMgr_Camera,
	TableMgr_Building,
	Camera,
	Max,
};

typedef TFunction<void(const FMessageHandler&)> MessageFunc;
class DSCORE_API IMgr
{
public:
	virtual ~IMgr() {}
	virtual EMgrIndex GetIndex() const = 0;

public:
	static void AddMgr(const EMgrIndex Index, IMgr* pMgr);
	static void InitMgr();
	static void ShutdownMgr();
	static void SendMessage(const FMessageHandler& rMessageHandler);

protected:
	static bool TickMgr(float fDeltaSeconds);
	virtual void OnInit() {}
	virtual void OnShutdown() {}
	virtual void OnTick(float fDeltaSeconds) {}
	static void Regist_MessageFunc(const UScriptStruct* pTargetStruct, MessageFunc Func);

private:
	static TSortedMap<EMgrIndex, IMgr*> ms_smapMgr;
	static FDelegateHandle ms_dgTickHandle;
	static TSortedMap<const UScriptStruct*, MessageFunc> ms_smapMessageFunc;
};