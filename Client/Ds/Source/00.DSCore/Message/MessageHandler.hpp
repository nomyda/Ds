#pragma once

template<class Message>
Message* FMessageHandler::Get_Or_Add()
{
	const Message* cpMessage = Get<Message>();
	if (cpMessage)
		return const_cast<Message*>(cpMessage);

	UScriptStruct* pTargettStruct = Message::StaticStruct();
	if (nullptr == pTargettStruct)
		return nullptr;

	UScriptStruct* pStoreStruct = FMessageBase::StaticStruct();
	if (false == pTargettStruct->IsChildOf(pStoreStruct))
		return nullptr;

	m_ScriptStruct = pTargettStruct;
	m_spMessage = TSharedPtr<FMessageBase>(new Message);
	return static_cast<Message*>(m_spMessage.Get());
}

template<class Message>
const Message* FMessageHandler::Get() const
{
	if(nullptr == m_ScriptStruct || false == m_spMessage.IsValid())
		return nullptr;

	UScriptStruct* pTargettStruct = Message::StaticStruct();
	if(nullptr == pTargettStruct)
		return nullptr;

	if (false == m_ScriptStruct->IsChildOf(pTargettStruct))
		return nullptr;

	return static_cast<const Message*>(m_spMessage.Get());
}