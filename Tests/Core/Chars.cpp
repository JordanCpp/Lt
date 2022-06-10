#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Chars.hpp>

void TestCharsCompare()
{
	LT_TEST_EQUAL(Lt::Chars::Compare("Hello", "Hello") == 0);
	LT_TEST_EQUAL(Lt::Chars::Compare("hello", "Hello") > 0);
	LT_TEST_EQUAL(Lt::Chars::Compare("Hello", "hello") < 0);
}

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

void TestCharsCopy()
{
	const Lt::usize bytes = 32;

	char buffer[bytes];

	Lt::Chars::Copy(buffer, "Hello world!", bytes);

	LT_TEST_EQUAL(Lt::Chars::Equal(buffer, "Hello world!") == true);
	LT_TEST_EQUAL(Lt::Chars::Length(buffer) == 12);
}

void TestCharsConcat()
{
	const Lt::usize bytes = 32;

	char buffer[bytes];

	Lt::Chars::Zero(buffer, bytes);

	Lt::Chars::Concat(buffer, "Hello", bytes);
	Lt::Chars::Concat(buffer, " ", bytes);
	Lt::Chars::Concat(buffer, "world", bytes);
	Lt::Chars::Concat(buffer, "!", bytes);

	LT_TEST_EQUAL(Lt::Chars::Equal(buffer, "Hello world!") == true);
	LT_TEST_EQUAL(Lt::Chars::Length(buffer) == 12);
}

void TestCharsZero()
{
	const Lt::usize bytes = 32;

	char buffer[bytes];

	Lt::Chars::Zero(buffer, bytes);

	LT_TEST_EQUAL(Lt::Chars::Length(buffer) == 0);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer[i] == '\0');
	}
}

int main()
{
	TestCharsCompare();
	TestCharsLength();
	TestCharsEqual();
	TestCharsIsSpace();
	TestCharsIsDigit();
	TestCharsCopy();
	TestCharsConcat();
	TestCharsZero();

	return 0;
}