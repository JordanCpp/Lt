#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/StringToInteger.hpp>
#include <Lt/Core/Chars.hpp>
#include <Lt/Containers/String.hpp>

void TestStringToIntegerChars()
{
	Lt::Core::StringToInteger convert;

	LT_TEST_EQUAL(convert.Convert("+100500") == true);
	LT_TEST_EQUAL(convert.Result() == 100500);

	LT_TEST_EQUAL(convert.Convert("C++") == false);
	LT_TEST_EQUAL(convert.Result() == 0);
}

void TestStringToIntegerString()
{
	Lt::Core::StringToInteger convert;

	Lt::Containers::String stringGood;
	stringGood.Assign("+100500");

	LT_TEST_EQUAL(convert.Convert(stringGood) == true);
	LT_TEST_EQUAL(convert.Result() == 100500);

	Lt::Containers::String stringBad;
	stringBad.Assign("C++");

	LT_TEST_EQUAL(convert.Convert(stringBad) == false);
	LT_TEST_EQUAL(convert.Result() == 0);
}


int main()
{
	TestStringToIntegerChars();
	TestStringToIntegerString();

	return 0;
}