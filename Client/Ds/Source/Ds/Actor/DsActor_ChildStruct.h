#pragma once
#include "DsActor_ChildStruct.generated.h"

enum class EActor_ChildStructType
{
	Info,
	Ctrl,
	Max,
};

class DsActor;
USTRUCT()
struct FDsActor_ChildStruct
{
	GENERATED_BODY()
public:
	virtual ~FDsActor_ChildStruct() {}
};
