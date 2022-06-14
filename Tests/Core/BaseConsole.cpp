#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/BaseConsole.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::BaseConsole baseConsole;
	LT_TEST_EQUAL(Lt::Chars::Equal(baseConsole.Result(), ""));

	baseConsole.Append("Hello");
	LT_TEST_EQUAL(Lt::Chars::Equal(baseConsole.Result(), "Hello"));

	baseConsole.Append(" world!");
	LT_TEST_EQUAL(Lt::Chars::Equal(baseConsole.Result(), "Hello world!"));

	baseConsole.Line();
	LT_TEST_EQUAL(Lt::Chars::Equal(baseConsole.Result(), "Hello world!\n"));

	baseConsole.Clear();
	LT_TEST_EQUAL(Lt::Chars::Equal(baseConsole.Result(), ""));

	return 0;
}