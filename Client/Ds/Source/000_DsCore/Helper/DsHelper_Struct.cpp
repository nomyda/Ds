#include "DsHelper_Struct.h"

bool DsHelper_Struct::IsCastEnable(const UScriptStruct* pBaseStruct, const UScriptStruct* pTargetStruct)
{
	if (nullptr == pBaseStruct || nullptr == pTargetStruct)
		return false;

	const bool bCastEnable = pTargetStruct->IsChildOf(pBaseStruct);
	return bCastEnable;
}