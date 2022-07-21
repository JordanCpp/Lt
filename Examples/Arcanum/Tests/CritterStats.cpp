#include <Lt/Core/TestEqual.hpp>
#include "../Gameplay/CritterStats.hpp"

void TestCritterStatsInit()
{
	Arcanum::Gameplay::CritterStats critterStats;

	for (Lt::usize i = 0; i < critterStats.Max; i++)
	{
		LT_TEST_EQUAL(critterStats.Value(i) == 0);
		LT_TEST_EQUAL(critterStats.Number(i) == 0);
		LT_TEST_EQUAL(critterStats.Percent(i) == 0);
	}
}

void TestCritterStatsSet()
{
	Arcanum::Gameplay::CritterStats critterStats;

	for (Lt::usize i = 0; i < critterStats.Max; i++)
	{
		critterStats.Value(i, 32);
		critterStats.Number(i,64);
		critterStats.Percent(i, 128);
	}

	for (Lt::usize i = 0; i < critterStats.Max; i++)
	{
		LT_TEST_EQUAL(critterStats.Value(i) == 32);
		LT_TEST_EQUAL(critterStats.Number(i) == 64);
		LT_TEST_EQUAL(critterStats.Percent(i) == 128);
	}
}

int main()
{
	TestCritterStatsInit();
	TestCritterStatsSet();

	return 0;
}