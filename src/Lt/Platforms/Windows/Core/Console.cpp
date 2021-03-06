#include <Lt/Platforms/Windows/Core/Console.hpp>
#include <Lt/Core/Chars.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Core::Windows::Console::Console():
	_Input(nullptr),
	_Output(nullptr)
{
	_Input = GetStdHandle(STD_INPUT_HANDLE);

	LT_ASSERT(_Input != INVALID_HANDLE_VALUE);

	_Output = GetStdHandle(STD_OUTPUT_HANDLE);

	LT_ASSERT(_Output != INVALID_HANDLE_VALUE);
}

Lt::Core::Windows::Console::~Console()
{
}

void Lt::Core::Windows::Console::Show()
{
	DWORD count = 0;

	WriteConsole(_Output, _BaseConsole.Result(), (DWORD)Lt::Chars::Length(_BaseConsole.Result()), &count, nullptr);

	_BaseConsole.Clear();
}

void Lt::Core::Windows::Console::Line()
{
	_BaseConsole.Line();
}

void Lt::Core::Windows::Console::Write(const char* source)
{
	_BaseConsole.Append(source);
}

void Lt::Core::Windows::Console::Write(const Lt::Containers::String& source)
{
	_BaseConsole.Append(source);
}

void Lt::Core::Windows::Console::Write(Lt::isize source)
{
	if (_Convert.Convert(source))
	{
		Write(_Convert.Result());
	}
}