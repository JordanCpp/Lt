#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Convert.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::Convert convert;

	LT_TEST_EQUAL(convert.ToString(197456) == true);

	LT_TEST_EQUAL(Lt::Chars::Equal(convert.Result(), "197456"));

	return 0;
}