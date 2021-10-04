#pragma once

template<class MessageStruct>
bool TClassMsg<MessageStruct>::Send()
{
	if (false == IsBound() || m_bSend)
		return false;

	m_bSend = true;
	ms_OnClassMsg.Broadcast(static_cast<const MessageStruct&>(*this));
	return true;
}

template<class MessageStruct>
bool TClassMsg<MessageStruct>::IsBound()
{
	return ms_OnClassMsg.IsBound();
}
