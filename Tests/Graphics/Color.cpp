#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Color.hpp>

void TestGraphicsColorDefault()
{
	Lt::Graphics::Color color;

	LT_TEST_EQUAL(color.Red() == 0);
	LT_TEST_EQUAL(color.Green() == 0);
	LT_TEST_EQUAL(color.Blue() == 0);
	LT_TEST_EQUAL(color.Alpha() == 255);
}

void TestGraphicsColorManualNoAlpha()
{
	Lt::Graphics::Color color(15, 20, 25);

	LT_TEST_EQUAL(color.Red() == 15);
	LT_TEST_EQUAL(color.Green() == 20);
	LT_TEST_EQUAL(color.Blue() == 25);
	LT_TEST_EQUAL(color.Alpha() == 255);
}

void TestGraphicsColorManualYesAlpha()
{
	Lt::Graphics::Color color(15, 20, 25, 100);

	LT_TEST_EQUAL(color.Red() == 15);
	LT_TEST_EQUAL(color.Green() == 20);
	LT_TEST_EQUAL(color.Blue() == 25);
	LT_TEST_EQUAL(color.Alpha() == 100);
}

int main()
{
	TestGraphicsColorDefault();
	TestGraphicsColorManualNoAlpha();
	TestGraphicsColorManualYesAlpha();

	return 0;
}