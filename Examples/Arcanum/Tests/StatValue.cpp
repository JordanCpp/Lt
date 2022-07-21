#include <Lt/Core/TestEqual.hpp>
#include "../Gameplay/StatValue.hpp"

void TestStatValueInit()
{
	Arcanum::Gameplay::StatValue statValue;

	LT_TEST_EQUAL(statValue.Value() == 0);
	LT_TEST_EQUAL(statValue.Number() == 0);
	LT_TEST_EQUAL(statValue.Percent() == 0);
}

void TestStatValueSet()
{
	Arcanum::Gameplay::StatValue statValue;

	statValue.Value(1);
	LT_TEST_EQUAL(statValue.Value() == 1);

	statValue.Number(2);
	LT_TEST_EQUAL(statValue.Number() == 2);

	statValue.Percent(3);
	LT_TEST_EQUAL(statValue.Percent() == 3);
}

int main()
{
	TestStatValueInit();
	TestStatValueSet();

	return 0;
}