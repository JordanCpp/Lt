#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuWindow.hpp>

void TestGraphicscpuWindow()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::CpuWindow window(errorHandler, Lt::Graphics::Point2i(25, 50), Lt::Graphics::Point2i(800, 600), "Window!");

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
	TestGraphicscpuWindow();

	return 0;
}