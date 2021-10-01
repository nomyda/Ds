#pragma once
#include "TClassMsg.h"

struct DSCORE_API FDsClassMsg_Log : public TClassMsg<FDsClassMsg_Log>
{
public:
	template <class FmtType, class... ArgTypes>
	FDsClassMsg_Log(const FmtType& fmt, ArgTypes&&... args)
	{
		m_Log = FString::Printf(fmt, Forward<ArgTypes>(args)...);
	}

private:
	FString m_Log;
};