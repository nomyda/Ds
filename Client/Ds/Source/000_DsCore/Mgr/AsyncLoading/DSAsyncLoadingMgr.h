#pragma once
#include "Singleton/DsSingleton_Static.h"
#include "Engine/StreamableManager.h"

static const uint32 InvalidAsyncLoadingID = 0;
typedef TSharedPtr<FStreamableHandle> SharedStreamableHandle;
DECLARE_DELEGATE_TwoParams(FOnLoadingComplete, const uint32, UObject*);
struct DSAsyncLoadingInfo
{
public:
	SharedStreamableHandle m_HandlePtr;
	TArray<FOnLoadingComplete> m_ArrDelegate_OnLoadingComplete;
};

class DSCORE_API DSAsyncLoadingMgr : public DsSingleton_Static<DSAsyncLoadingMgr>
{
public:
	DSAsyncLoadingMgr();
	~DSAsyncLoadingMgr();

	bool IsValid() const;
	uint32 RequestAsyncLoading(const FSoftObjectPath& Path, FOnLoadingComplete rDelegate_OnLoadingComplete);
	bool CancelAsyncLoading(const uint32 AsyncLoadingID);

protected:
	FStreamableManager& GetStreamableM() const;

private:
	void OnLoadingComplete();

	typedef TSortedMap<uint32, DSAsyncLoadingInfo> SMap_AsyncLoadID_And_LoadingInfo;
	SMap_AsyncLoadID_And_LoadingInfo m_smapAsyncLoadID_And_AsyncLoadingInfo;
	uint32 m_AsyncLoadID;
};