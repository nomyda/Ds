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
	FDsClassMsg_Log(const FString& Log) 
		: m_Log(Log)
	{

	}

public:
	FString m_Log;
};


#define DebugInfoString FString::Printf(TEXT(", Func{%s}, File{%s}, Line{%d}"), *FString(__FUNCTION__), *FString(__FILE__), __LINE__)

#define Log_Include_DebugInfo 0
#if Log_Include_DebugInfo
#define DsLog(fmt, ...) \
{\
	FString CurLog = FString::Printf(fmt, ##__VA_ARGS__);\
	CurLog.Append(*DebugInfoString);\
	FDsClassMsg_Log kLog(CurLog);\
	kLog.Send();\
}
#else	// Log_Include_DebugInfo
#define DsLog(fmt, ...) \
{\
	FString CurLog = FString::Printf(fmt, ##__VA_ARGS__);\
	FDsClassMsg_Log kLog(CurLog);\
	kLog.Send();\
}
#endif	// Log_Include_DebugInfo