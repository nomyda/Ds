#pragma once
#include "Engine/DataTable.h"
#include "DsTable_Base.generated.h"

USTRUCT()
struct FDsTable_Base : public FTableRowBase
{
	GENERATED_BODY()

public:
	virtual ~FDsTable_Base() {}
};