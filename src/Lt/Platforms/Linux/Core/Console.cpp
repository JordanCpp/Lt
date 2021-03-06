#include <Lt/Platforms/Linux/Core/Console.hpp>
#include <Lt/Core/Chars.hpp>
#include <unistd.h>

Lt::Core::Linux::Console::Console()
{
}

Lt::Core::Linux::Console::~Console()
{
}

void Lt::Core::Linux::Console::Show()
{
	write(1, _BaseConsole.Result(), Lt::Chars::Length(_BaseConsole.Result())); 

	_BaseConsole.Clear();
}

void Lt::Core::Linux::Console::Line()
{
	_BaseConsole.Line();
}

void Lt::Core::Linux::Console::Write(const char* source)
{
	_BaseConsole.Append(source);
}

void Lt::Core::Linux::Console::Write(const Lt::Containers::String& source)
{
	_BaseConsole.Append(source);
}

void Lt::Core::Linux::Console::Write(Lt::isize source)
{
	if (_Convert.Convert(source))
	{
		Write(_Convert.Result());
	}
}