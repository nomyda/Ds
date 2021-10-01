#pragma once

/*
* ��ӹ��� �޽��� ����ü�� �ݵ�� DSCORE_API �� ���� api�� �־��ٰ�
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