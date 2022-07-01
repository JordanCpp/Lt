#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Cpu/CpuWindow.hpp>

void TestGraphicsCpuWindow()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::CpuWindow window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(window.Pos().PosX() == 25);
	LT_TEST_EQUAL(window.Pos().PosY() == 50);
	LT_TEST_EQUAL(window.Size().PosX() == 800);
	LT_TEST_EQUAL(window.Size().PosY() == 600);
	LT_TEST_EQUAL(Lt::Chars::Equal(window.Title(), "Window!"));

	Lt::Events::Event event;

	LT_TEST_EQUAL(window.GetEvent(event) == true);

	window.StopEvent();

	LT_TEST_EQUAL(window.GetEvent(event) == false);
}
int main()
{
	TestGraphicsCpuWindow();

	return 0;
}