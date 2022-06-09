#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/IntegerToString.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::IntegerToString convert;

	LT_TEST_EQUAL(convert.Convert(100500) == true);

	LT_TEST_EQUAL(Lt::Chars::Equal(convert.Result(), "100500"));

	return 0;
}