#pragma once
#include "IMgr.h"
#include "Pattern\DSSingleton.h"

/*
* �Ŵ��� ���ø� Ŭ����
*/
template<class MgrClass>
class TMgr : public IMgr, public DSSingleton<MgrClass>
{
public:
	virtual ~TMgr() {}
	typedef MgrClass MgrClassType;

	void OnSingleton() final
	{
		const EMgrIndex Index = GetIndex();
		IMgr::AddMgr(Index, this);
		OnInit();
	}
};