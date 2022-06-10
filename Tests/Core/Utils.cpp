#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Utils.hpp>

void TestUtilsIsLeapYear()
{
	LT_TEST_EQUAL(Lt::Core::Utils::IsLeapYear(2020) == true);

	LT_TEST_EQUAL(Lt::Core::Utils::IsLeapYear(2021) == false);
}

int main()
{
	TestUtilsIsLeapYear();

	return 0;
}