#pragma once
#include "IMgr.h"
#include "Singleton/DsSingleton_Static.h"
#include "Message/DsClassMsg_InitGame.h"



struct FDsClassMsg_InitGame;

/*
* 매니저 템플릿 클래스
*/
template<class MgrClass>
class TMgr : public IMgr, public DsSingleton_Static<MgrClass>
{
public:
	TMgr() : IMgr() 
	{
		m_hInitM = FDsClassMsg_InitGame::GetDelegate().AddRaw(this, &TMgr<MgrClass>::OnMsg_InitM);
	}
	virtual ~TMgr() {}

private:
	virtual void OnMsg_InitM(const FDsClassMsg_InitGame& rMsg)
	{
		const EMgr_Index eIndex = GetIndex();
		IMgr::AddM(eIndex, *this);
	}

private:
	FDelegateHandle m_hInitM;
};