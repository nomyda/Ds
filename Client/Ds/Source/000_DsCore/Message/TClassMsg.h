#pragma once

/*
* 상속받은 메시지 구조체에 반드시 DSCORE_API 와 같은 api를 넣어줄것 => 외부 모듈에 멤버함수가 사용될수 있도록
*/
template<class MessageStruct>
struct TClassMsg
{
public:
	TClassMsg() : m_bSend(false) {}
	virtual ~TClassMsg() { Send(); }
	typedef TMulticastDelegate<void(const MessageStruct&)> FOnClassMsg;

	bool Send();
	static bool IsBound();
	static FOnClassMsg& OnClassMsg() { return ms_OnClassMsg; }

private:
	static FOnClassMsg ms_OnClassMsg;
	bool m_bSend;
};

template<class MessageStruct>
TMulticastDelegate<void(const MessageStruct&)> TClassMsg<MessageStruct>::ms_OnClassMsg;

#include "TClassMsg.hpp"