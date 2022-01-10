#pragma once
#include "TTableMgr.h"

struct FDSActorTable;
class DSTABLE_API DSActorTableM : public TTableM<FDSActorTable, DSActorTableM>
{
public:
	EMgrIndex GetIndex() const override;
	void OnInit() override;
	static void Messag(const FMessageHandler& rMessageHandler);
};