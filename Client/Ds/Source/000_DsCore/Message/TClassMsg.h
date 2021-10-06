#pragma once

/*
* ��ӹ��� �޽��� ����ü�� �ݵ�� DSCORE_API �� ���� api�� �־��ٰ� => �ܺ� ��⿡ ����Լ��� ���ɼ� �ֵ���

[�̽�]
- �ش����Ͽ� �ִ� �����ڿ��� ��������Ʈ ���ε� �ϴ� ���� �� �۵�������, cpp���Ͽ� �ִ� �����ڿ��� ���ε� �ϸ� �ȵǴ� ������ �ִ�
*/
template<class MessageStruct>
struct TClassMsg
{
public:
	TClassMsg() : m_bSend(false) {}
	virtual ~TClassMsg();
	typedef TMulticastDelegate<void(const MessageStruct&)> FOnClassMsg;

	bool Send();
	static bool IsBound();
	static FOnClassMsg& GetDelegate() 
	{ 
		return TClassMsg<MessageStruct>::ms_OnClassMsg;
	}

private:
	static FOnClassMsg ms_OnClassMsg;
	bool m_bSend;
};

template<class MessageStruct>
TMulticastDelegate<void(const MessageStruct&)> TClassMsg<MessageStruct>::ms_OnClassMsg;

#include "TClassMsg.hpp"