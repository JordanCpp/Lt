#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/GetSystemDateTime.hpp>

void TestCoreGetSystemDateTime()
{
	Lt::Core::SystemDateTime dt;

	Lt::Core::GetSystemDateTime(dt);

	LT_TEST_EQUAL(dt.Years > 0);
	LT_TEST_EQUAL(dt.Months > 0);
	LT_TEST_EQUAL(dt.Days > 0);
}

int main()
{
	TestCoreGetSystemDateTime();

	return 0;
}