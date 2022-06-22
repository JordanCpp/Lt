#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/FpsCounter.hpp>
#include <Lt/Core/Ticks.hpp>

void TestGraphicsFpsCounter()
{
	const Lt::usize ms = 100;

	Lt::Graphics::FpsCounter fpsCounter;

	LT_TEST_EQUAL(fpsCounter.Fps() == 0);
	LT_TEST_EQUAL(fpsCounter.Calc() == false);

	Lt::Core::Delay(2000);

	for (Lt::usize i = 0; i < ms; i += ms)
	{
		fpsCounter.Calc();
	}

	LT_TEST_EQUAL(fpsCounter.Fps() > 0);

	fpsCounter.Clear();

	LT_TEST_EQUAL(fpsCounter.Fps() == 0);
	LT_TEST_EQUAL(fpsCounter.Calc() == false);
}

int main()
{
	TestGraphicsFpsCounter();

	return 0;
}