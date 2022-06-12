#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Utils.hpp>

void TestUtilsIsLeapYear()
{
	LT_TEST_EQUAL(Lt::Core::Utils::IsLeapYear(2020) == true);

	LT_TEST_EQUAL(Lt::Core::Utils::IsLeapYear(2021) == false);
}

void TestUtilsDateIsValid()
{
	LT_TEST_EQUAL(Lt::Core::Utils::DateIsValid(2020, 5,17) == true);

	LT_TEST_EQUAL(Lt::Core::Utils::DateIsValid(2020, 99, 17) == false);
}

void TestUtilsTimeIsValid()
{
	LT_TEST_EQUAL(Lt::Core::Utils::TimeIsValid(23, 58, 5) == true);

	LT_TEST_EQUAL(Lt::Core::Utils::TimeIsValid(25, 60, 60) == false);
}

int main()
{
	TestUtilsIsLeapYear();
	TestUtilsDateIsValid();
	TestUtilsTimeIsValid();

	return 0;
}