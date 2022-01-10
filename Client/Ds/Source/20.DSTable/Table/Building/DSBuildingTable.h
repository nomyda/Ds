#pragma once
#include "Table/DSBaseTable.h"
#include "DSBuildingTable.generated.h"

USTRUCT()
struct FDSBuildingTable : public FDSBaseTable
{
	GENERATED_BODY()

public:
	FDSBuildingTable()
		: Super()
	{

	}

	UPROPERTY(EditAnywhere) TArray<TSoftObjectPtr<UStreamableRenderAsset>> ModelMesh;
};