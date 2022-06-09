#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/StringToInteger.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::StringToInteger convert;

	LT_TEST_EQUAL(convert.Convert("+100500") == true);
	LT_TEST_EQUAL(convert.Result() == 100500);

	LT_TEST_EQUAL(convert.Convert("C++") == false);
	LT_TEST_EQUAL(convert.Result() == 0);

	return 0;
}