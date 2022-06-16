#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Window.hpp>

void TestGraphicsWindow()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2i(0, 0), Lt::Graphics::Point2i(800, 600), "Window!");

	LT_TEST_EQUAL(errorHandler.IsError() == false);
}
int main()
{
	TestGraphicsWindow();

	return 0;
}