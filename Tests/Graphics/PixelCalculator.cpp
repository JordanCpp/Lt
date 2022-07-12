#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/PixelCalculator.hpp>

void TestGraphicsPixelCalculatorBytesPerPixelEqual1()
{
	Lt::Graphics::PixelCalculator pixelCalculator;

	LT_TEST_EQUAL(pixelCalculator.Calc(Lt::Graphics::Point2u(800, 600), 1) == 480000);
}

void TestGraphicsPixelCalculatorBytesPerPixelEqual2()
{
	Lt::Graphics::PixelCalculator pixelCalculator;

	LT_TEST_EQUAL(pixelCalculator.Calc(Lt::Graphics::Point2u(800, 600), 2) == 960000);
}

void TestGraphicsPixelCalculatorBytesPerPixelEqual3()
{
	Lt::Graphics::PixelCalculator pixelCalculator;

	LT_TEST_EQUAL(pixelCalculator.Calc(Lt::Graphics::Point2u(800, 600), 3) == 1440000);
}

void TestGraphicsPixelCalculatorBytesPerPixelEqual4()
{
	Lt::Graphics::PixelCalculator pixelCalculator;

	LT_TEST_EQUAL(pixelCalculator.Calc(Lt::Graphics::Point2u(800, 600), 4) == 1920000);
}

int main()
{
	TestGraphicsPixelCalculatorBytesPerPixelEqual1();
	TestGraphicsPixelCalculatorBytesPerPixelEqual2();
	TestGraphicsPixelCalculatorBytesPerPixelEqual3();
	TestGraphicsPixelCalculatorBytesPerPixelEqual4();

	return 0;
}