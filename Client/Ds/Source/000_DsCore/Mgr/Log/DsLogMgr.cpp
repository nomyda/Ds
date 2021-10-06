#include "DsLogMgr.h"


void DsLogMgr::OnClassMessage(const FDsClassMsg_Log& rLog)
{
	static const bool bOutput = true;
	if (bOutput)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *rLog.m_Log);
	}

	static const bool bScreen = true;
	if (bScreen)
	{
		FColor FontColor = FColor::Blue;
		if (rLog.m_eType == ELogVerbosity::Warning ||
			rLog.m_eType == ELogVerbosity::Error ||
			rLog.m_eType == ELogVerbosity::Fatal)
			FontColor = FColor::Red;

		static const float DisplaySec = 3.0f;
		GEngine->AddOnScreenDebugMessage(-1, DisplaySec, FontColor, rLog.m_Log, true, FVector2D(1.5f, 1.5f));
	}
}