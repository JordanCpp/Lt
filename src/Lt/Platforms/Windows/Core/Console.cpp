#include <Lt/Platforms/Windows/Core/Console.hpp>
#include <Lt/Core/Chars.hpp>

Lt::Core::Console::Console()
{
	_Input = GetStdHandle(STD_INPUT_HANDLE);
	_Output = GetStdHandle(STD_OUTPUT_HANDLE);
}

Lt::Core::Console::~Console()
{
	CloseHandle(_Input);
	CloseHandle(_Output);
}

void Lt::Core::Console::Write(const char* source)
{
	DWORD count = 0;

	WriteConsole(_Output, source, (DWORD)Lt::Chars::Length(source), &count, nullptr);
}

void Lt::Core::Console::Write(Lt::isize source)
{
	if (_Convert.IntToStr(source))
	{
		Write(_Convert.Result());
	}
}