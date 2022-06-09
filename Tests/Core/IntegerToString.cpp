#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/IntegerToString.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::IntegerToString convert;

	LT_TEST_EQUAL(convert.Convert(197456) == true);

	LT_TEST_EQUAL(Lt::Chars::Equal(convert.Result(), "197456"));

	return 0;
}