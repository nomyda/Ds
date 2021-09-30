#pragma once
#include "IMgr.h"
#include "Singleton/DsSingleton_SharedPtr.h"

/*
* 매니저 템플릿 클래스
*/
template<class MgrClass>
class TMgr : public IMgr, public DsSingleton_SharedPtr<MgrClass>
{
public:
	virtual ~TMgr() {}
	void OnSingleton() override
	{
		const EMgr_Index eIndex = GetIndex();
		AddM(eIndex, *this);
	}
};