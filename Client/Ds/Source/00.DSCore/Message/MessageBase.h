#pragma once
#include "MessageBase.generated.h"

USTRUCT()
struct DSCORE_API FMessageBase
{
	GENERATED_BODY()

public:
	FMessageBase() {}
};

USTRUCT()
struct DSCORE_API FMessage_GameStart : public FMessageBase
{
	GENERATED_BODY()

public:
	FMessage_GameStart() {}
};