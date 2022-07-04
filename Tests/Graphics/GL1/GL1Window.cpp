#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/GL1/GL1Window.hpp>

void TestGraphicsGL1WindowInit()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::GL1Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "GL1Window!");

	LT_TEST_EQUAL(errorHandler.IsError() == false);

	LT_TEST_EQUAL(window.Pos().PosX() == 25);
	LT_TEST_EQUAL(window.Pos().PosY() == 50);
	LT_TEST_EQUAL(window.Size().PosX() == 800);
	LT_TEST_EQUAL(window.Size().PosY() == 600);

	LT_TEST_EQUAL(Lt::Chars::Equal(window.Title(), "GL1Window!"));

	Lt::Events::Event event;

	LT_TEST_EQUAL(window.GetEvent(event) == true);

	window.StopEvent();

	LT_TEST_EQUAL(window.GetEvent(event) == false);
}

int main()
{
	TestGraphicsGL1WindowInit();

	return 0;
}