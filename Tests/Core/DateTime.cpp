#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/DateTime.hpp>

void TestDateTimeSize()
{
	LT_TEST_EQUAL(sizeof(Lt::DateTime) == 8);
}

void TestDateTimeDefault()
{
	Lt::DateTime dt;

	LT_TEST_EQUAL(dt.Years() == 1900);
	LT_TEST_EQUAL(dt.Months() == 1);
	LT_TEST_EQUAL(dt.Days() == 1);
	LT_TEST_EQUAL(dt.Hours() == 0);
	LT_TEST_EQUAL(dt.Minutes() == 0);
	LT_TEST_EQUAL(dt.Seconds() == 0);
}

void TestDateTimeManual()
{
	Lt::DateTime dt(2022);
	LT_TEST_EQUAL(dt.Years() == 2022);
	LT_TEST_EQUAL(dt.Months() == 1);
	LT_TEST_EQUAL(dt.Days() == 1);
	LT_TEST_EQUAL(dt.Hours() == 0);
	LT_TEST_EQUAL(dt.Minutes() == 0);
	LT_TEST_EQUAL(dt.Seconds() == 0);

	Lt::DateTime dt2(2022, 5);
	LT_TEST_EQUAL(dt2.Years() == 2022);
	LT_TEST_EQUAL(dt2.Months() == 5);
	LT_TEST_EQUAL(dt2.Days() == 1);
	LT_TEST_EQUAL(dt2.Hours() == 0);
	LT_TEST_EQUAL(dt2.Minutes() == 0);
	LT_TEST_EQUAL(dt2.Seconds() == 0);

	Lt::DateTime dt3(2022, 5, 17);
	LT_TEST_EQUAL(dt3.Years() == 2022);
	LT_TEST_EQUAL(dt3.Months() == 5);
	LT_TEST_EQUAL(dt3.Days() == 17);
	LT_TEST_EQUAL(dt3.Hours() == 0);
	LT_TEST_EQUAL(dt3.Minutes() == 0);
	LT_TEST_EQUAL(dt3.Seconds() == 0);

	Lt::DateTime dt4(2022, 5, 17, 9);
	LT_TEST_EQUAL(dt4.Years() == 2022);
	LT_TEST_EQUAL(dt4.Months() == 5);
	LT_TEST_EQUAL(dt4.Days() == 17);
	LT_TEST_EQUAL(dt4.Hours() == 9);
	LT_TEST_EQUAL(dt4.Minutes() == 0);
	LT_TEST_EQUAL(dt4.Seconds() == 0);

	Lt::DateTime dt5(2022, 5, 17, 9, 42);
	LT_TEST_EQUAL(dt5.Years() == 2022);
	LT_TEST_EQUAL(dt5.Months() == 5);
	LT_TEST_EQUAL(dt5.Days() == 17);
	LT_TEST_EQUAL(dt5.Hours() == 9);
	LT_TEST_EQUAL(dt5.Minutes() == 42);
	LT_TEST_EQUAL(dt5.Seconds() == 0);

	Lt::DateTime dt6(2022, 5, 17, 9, 42, 57);
	LT_TEST_EQUAL(dt6.Years() == 2022);
	LT_TEST_EQUAL(dt6.Months() == 5);
	LT_TEST_EQUAL(dt6.Days() == 17);
	LT_TEST_EQUAL(dt6.Hours() == 9);
	LT_TEST_EQUAL(dt6.Minutes() == 42);
	LT_TEST_EQUAL(dt6.Seconds() == 57);
}

void TestDateTimeNow()
{
	Lt::DateTime dt;

	dt.Now();

	LT_TEST_EQUAL(dt.Years() > 1900);
	LT_TEST_EQUAL(dt.Months() > 0);
	LT_TEST_EQUAL(dt.Days() > 0);
	LT_TEST_EQUAL(dt.Hours() > 0);
	LT_TEST_EQUAL(dt.Minutes() > 0);
	LT_TEST_EQUAL(dt.Seconds() > 0);
}

int main()
{
	TestDateTimeSize();
	TestDateTimeDefault();
	TestDateTimeManual();
	TestDateTimeNow();

	return 0;
}