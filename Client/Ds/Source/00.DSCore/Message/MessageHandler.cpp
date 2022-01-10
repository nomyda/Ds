#include "MessageHandler.h"

FMessageHandler::FMessageHandler()
: m_ScriptStruct(nullptr)
{

}

FMessageHandler::~FMessageHandler()
{
	m_spMessage.Reset();
}