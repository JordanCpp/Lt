#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Window.hpp>

void TestGraphicsWindow()
{
	Lt::Graphics::Window window(Lt::Graphics::Point2i(0, 0), Lt::Graphics::Point2i(800, 600), "Window!");

	LT_TEST_EQUAL(window.IsError() == false);
}
int main()
{
	TestGraphicsWindow();

	return 0;
}