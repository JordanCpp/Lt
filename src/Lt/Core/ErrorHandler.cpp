#include <Lt/Core/ErrorHandler.hpp>

Lt::Core::ErrorHandler::ErrorHandler() :
	_IsError(false)
{
}

bool Lt::Core::ErrorHandler::IsError()
{
	return _IsError;
}

const char* Lt::Core::ErrorHandler::Message()
{
	return _Message.Content();
}

void Lt::Core::ErrorHandler::Message(const char* description)
{
	_IsError = true;

	_Message.Assign(description);
}

void Lt::Core::ErrorHandler::Reset()
{
	_IsError = false;

	_Message.Clear();
}