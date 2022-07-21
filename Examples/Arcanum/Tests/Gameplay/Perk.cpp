#include <Lt/Core/TestEqual.hpp>
#include "../../Gameplay/Perk.hpp"
#include "../../Gameplay/CritterStats.hpp"

void TestGameplayPerkInit()
{
	Arcanum::Gameplay::Perk perk;

	LT_TEST_EQUAL(perk.Length() == 0);
	LT_TEST_EQUAL(perk.Capacity() == Arcanum::Gameplay::Perk::Max);
}

void TestGameplayPerkAdd()
{
	Arcanum::Gameplay::Perk perk;

	perk.Add(Arcanum::Gameplay::Attribute(Arcanum::Gameplay::CritterStats::Dexterity, 55, 35));

	LT_TEST_EQUAL(perk.Length() == 1);
	LT_TEST_EQUAL(perk.Id(0) == Arcanum::Gameplay::CritterStats::Dexterity);
	LT_TEST_EQUAL(perk.Number(0) == 55);
	LT_TEST_EQUAL(perk.Percent(0) == 35);
}

int main()
{
	TestGameplayPerkInit();
	TestGameplayPerkAdd();

	return 0;
}