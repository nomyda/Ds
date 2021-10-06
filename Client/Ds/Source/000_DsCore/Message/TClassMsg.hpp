#pragma once

template<class MessageStruct>
TClassMsg<MessageStruct>::~TClassMsg()
{
	if (m_bSend)
		return;

	Send();
}

template<class MessageStruct>
bool TClassMsg<MessageStruct>::Send()
{
	if (false == IsBound() || m_bSend)
		return false;

	m_bSend = true;
	GetDelegate().Broadcast(static_cast<const MessageStruct&>(*this));
	return true;
}

template<class MessageStruct>
bool TClassMsg<MessageStruct>::IsBound()
{
	return GetDelegate().IsBound();
}