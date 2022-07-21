#include <Lt/Core/TestEqual.hpp>
#include "../../Gameplay/Attribute.hpp"

void TestGameplayAttributeInit()
{
	Arcanum::Gameplay::Attribute attribute;

	LT_TEST_EQUAL(attribute.Number() == 0);
	LT_TEST_EQUAL(attribute.Percent() == 0);
}

void TestGameplayAttributeSet()
{	
	Arcanum::Gameplay::Attribute attribute;

	attribute.Number(1);
	LT_TEST_EQUAL(attribute.Number() == 1);

	attribute.Percent(2);
	LT_TEST_EQUAL(attribute.Percent() == 2);
}

int main()
{
	TestGameplayAttributeInit();
	TestGameplayAttributeSet();

	return 0;
}