#pragma once

template<class MessageStruct>
bool TClassMsg<MessageStruct>::Send() const
{
	if (false == IsBound())
		return false;

	ms_OnClassMsg.Broadcast(static_cast<const MessageStruct&>(*this));
	return true;
}

template<class MessageStruct>
bool TClassMsg<MessageStruct>::IsBound()
{
	return ms_OnClassMsg.IsBound();
}
