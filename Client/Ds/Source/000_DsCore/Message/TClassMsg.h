#pragma once

/*
* 상속받은 메시지 구조체에 반드시 DSCORE_API 와 같은 api를 넣어줄것
*/
template<class MessageStruct>
struct TClassMsg
{
public:
	virtual ~TClassMsg() {}
	typedef TMulticastDelegate<void(const MessageStruct&)> FOnClassMsg;

	bool Send() const;
	static bool IsBound();
	static FOnClassMsg& OnClassMsg() { return ms_OnClassMsg; }

private:
	static FOnClassMsg ms_OnClassMsg;
};

template<class MessageStruct>
TMulticastDelegate<void(const MessageStruct&)> TClassMsg<MessageStruct>::ms_OnClassMsg;

#include "TClassMsg.hpp"