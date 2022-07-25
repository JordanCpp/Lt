#include <Lt/Core/ErrorHandler.hpp>

Lt::Core::ErrorHandler::ErrorHandler() :
	_Error(false)
{
}

bool Lt::Core::ErrorHandler::Error()
{
	return _Error;
}

bool Lt::Core::ErrorHandler::Ok()
{
	return !Error();
}

const char* Lt::Core::ErrorHandler::Message() const
{
	return _Message.Content();
}

void Lt::Core::ErrorHandler::Message(const char* description)
{
	_Error = true;

	_Message.Assign(description);
}

void Lt::Core::ErrorHandler::Append(const char* description)
{
	_Error = true;

	_Message.Append(description);
}

void Lt::Core::ErrorHandler::Reset()
{
	_Error = false;

	_Message.Clear();
}