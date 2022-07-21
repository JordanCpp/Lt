#include <Lt/Core/TestEqual.hpp>
#include "../../Gameplay/Attribute.hpp"

void TestGameplayAttributeInit()
{
	Arcanum::Gameplay::Attribute attribute;

	LT_TEST_EQUAL(attribute.Id() == 0);
	LT_TEST_EQUAL(attribute.Number() == 0);
	LT_TEST_EQUAL(attribute.Percent() == 0);
}

void TestGameplayAttributeInitId()
{
	Arcanum::Gameplay::Attribute attribute(42);

	LT_TEST_EQUAL(attribute.Id() == 42);
	LT_TEST_EQUAL(attribute.Number() == 0);
	LT_TEST_EQUAL(attribute.Percent() == 0);
}

void TestGameplayAttributeInitIdAndNumber()
{
	Arcanum::Gameplay::Attribute attribute(42, 55);

	LT_TEST_EQUAL(attribute.Id() == 42);
	LT_TEST_EQUAL(attribute.Number() == 55);
	LT_TEST_EQUAL(attribute.Percent() == 0);
}

void TestGameplayAttributeInitIdAndPercent()
{
	Arcanum::Gameplay::Attribute attribute(42, 55, 75);

	LT_TEST_EQUAL(attribute.Id() == 42);
	LT_TEST_EQUAL(attribute.Number() == 55);
	LT_TEST_EQUAL(attribute.Percent() == 75);
}

void TestGameplayAttributeSet()
{	
	Arcanum::Gameplay::Attribute attribute(42);

	attribute.Number(1);
	LT_TEST_EQUAL(attribute.Number() == 1);

	attribute.Percent(2);
	LT_TEST_EQUAL(attribute.Percent() == 2);
}

int main()
{
	void TestGameplayAttributeInit();
	void TestGameplayAttributeInitId();
	void TestGameplayAttributeInitIdAndNumber();
	void TestGameplayAttributeInitIdAndPercent();
	void TestGameplayAttributeSet();

	return 0;
}