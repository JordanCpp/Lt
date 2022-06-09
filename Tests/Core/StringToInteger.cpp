#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/StringToInteger.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::StringToInteger convert;

	LT_TEST_EQUAL(convert.Convert("197456") == true);

	LT_TEST_EQUAL(convert.Result() == 197456);

	return 0;
}