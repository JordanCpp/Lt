#include "Lt/Core/BaseConsole.hpp"
#include <Lt/Core/Chars.hpp>

Lt::Core::BaseConsole::BaseConsole()
{
	Clear();
}

void Lt::Core::BaseConsole::Append(const char* source)
{
	Lt::Chars::Concat(_Buffer, source, BufferMax);
}

void Lt::Core::BaseConsole::Line()
{
	Lt::Chars::Concat(_Buffer, "\n", BufferMax);
}

void Lt::Core::BaseConsole::Clear()
{
	_Buffer[0] = '\0';
}

const char* Lt::Core::BaseConsole::Result()
{
	return _Buffer;
}
