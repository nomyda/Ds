#pragma once
#include "MessageBase.h"

class DSCORE_API FMessageHandler
{
public:
	FMessageHandler();
	~FMessageHandler();
	
	template<class Message>
	Message* Get_Or_Add();

	template<class Message>
	const Message* Get() const;

	const UScriptStruct* GetScriptStruct() const { return m_ScriptStruct; }

private:
	UScriptStruct* m_ScriptStruct;
	TSharedPtr<FMessageBase> m_spMessage;
};

#include "MessageHandler.hpp"