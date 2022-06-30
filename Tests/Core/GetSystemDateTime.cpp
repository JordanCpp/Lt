#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/GetSystemDateTime.hpp>
#include <Lt/Core/Memory.hpp>

void TestCoreGetSystemDateTime()
{
	Lt::Core::SystemDateTime dt;

	Lt::Memory::Zero(&dt, sizeof(Lt::Core::SystemDateTime));

	Lt::Core::GetSystemDateTime(dt);

	LT_TEST_EQUAL(dt.Years > 0);
	LT_TEST_EQUAL(dt.Months > 0);
	LT_TEST_EQUAL(dt.Days > 0);
	LT_TEST_EQUAL(dt.Hours > 0);
	LT_TEST_EQUAL(dt.Minutes > 0);
	LT_TEST_EQUAL(dt.Seconds > 0);
}

int main()
{
	TestCoreGetSystemDateTime();

	return 0;
}