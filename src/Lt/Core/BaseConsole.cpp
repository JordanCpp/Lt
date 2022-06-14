#include "Lt/Core/BaseConsole.hpp"
#include <Lt/Core/Chars.hpp>

Lt::Core::BaseConsole::BaseConsole()
{
	Clear();
}

void Lt::Core::BaseConsole::Append(const char* source)
{
	_Buffer.Append(source);
}

void Lt::Core::BaseConsole::Line()
{
	_Buffer.Append("\n");
}

void Lt::Core::BaseConsole::Clear()
{
	_Buffer[0] = '\0';
}

const char* Lt::Core::BaseConsole::Result()
{
	return _Buffer.Content();
}