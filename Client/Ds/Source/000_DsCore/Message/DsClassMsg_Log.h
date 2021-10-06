#pragma once
#include "TClassMsg.h"

struct DSCORE_API FDsClassMsg_Log : public TClassMsg<FDsClassMsg_Log>
{
public:
	template <class FmtType, class... ArgTypes>
	FDsClassMsg_Log(const TCHAR* LogCategory, const ELogVerbosity::Type eLogType, const FmtType& fmt, ArgTypes&&... args)
		: m_LogCategory(LogCategory)
		, m_eType(eLogType)
	{
		m_Log = FString::Printf(fmt, Forward<ArgTypes>(args)...);
	}
	FDsClassMsg_Log(const TCHAR* LogCategory, const ELogVerbosity::Type eLogType, const FString& Log)
		: m_LogCategory(LogCategory)
		, m_eType(eLogType)
		, m_Log(Log)
	{

	}

public:
	const TCHAR* m_LogCategory;
	const ELogVerbosity::Type m_eType;
	FString m_Log;
};


#define DebugInfoString FString::Printf(TEXT(", Func{%s}, File{%s}, Line{%d}"), *FString(__FUNCTION__), *FString(__FILE__), __LINE__)

#define Log_Include_DebugInfo 1
#if Log_Include_DebugInfo
#define DsLog(LogCategory, eLogType, fmt, ...) \
{\
	FString CurLog = FString::Printf(fmt, ##__VA_ARGS__);\
	CurLog.Append(*DebugInfoString);\
	FDsClassMsg_Log kLog(LogCategory, eLogType, CurLog);\
	kLog.Send();\
}
#else	// Log_Include_DebugInfo
#define DsLog(LogCategory, eLogType, fmt, ...) \
{\
	FString CurLog = FString::Printf(fmt, ##__VA_ARGS__);\
	FDsClassMsg_Log kLog(LogCategory, eLogType, CurLog);\
	kLog.Send();\
}
#endif	// Log_Include_DebugInfo