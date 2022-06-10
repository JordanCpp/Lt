#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Chars.hpp>

void TestCharsLength()
{
	char buffer[] = "Hello!";

	LT_TEST_EQUAL(Lt::Chars::Length(buffer) == 6);
}

void TestCharsEqual()
{
	char x[] = "Hello!";
	char y[] = "Hello!";

	LT_TEST_EQUAL(Lt::Chars::Equal(x, y) == true);

	char x2[] = "Hello!";
	char y2[] = "Goodbuy!";

	LT_TEST_EQUAL(Lt::Chars::Equal(x2, y2) == false);
}

void TestCharsIsSpace()
{
	LT_TEST_EQUAL(Lt::Chars::IsSpace(' ') == true);
	LT_TEST_EQUAL(Lt::Chars::IsSpace('x') == false);
}

void TestCharsIsDigit()
{
	LT_TEST_EQUAL(Lt::Chars::IsDigit('0') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('1') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('2') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('3') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('4') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('5') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('6') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('7') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('8') == true);
	LT_TEST_EQUAL(Lt::Chars::IsDigit('9') == true);

	LT_TEST_EQUAL(Lt::Chars::IsDigit('x') == false);

}

int main()
{
	TestCharsLength();
	TestCharsEqual();
	TestCharsIsSpace();
	TestCharsIsDigit();

	return 0;
}