#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Screenshoter.hpp>
#include <Lt/Core/BinaryFile.hpp>

void TestGraphicsScreenshoter()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(errorHandler, &window);
	Lt::Graphics::Screenshoter screenshoter(&render, "TestFiles/");
	Lt::Core::BinaryFile binaryFile;

	render.Color(Lt::Graphics::Color(156, 32, 78));
	render.Clear();

	screenshoter.Shot("screen.png");

	LT_TEST_EQUAL(binaryFile.Exist("TestFiles/screen.png") == true);

	binaryFile.Delete("TestFiles/screen.png");
}

int main()
{
	TestGraphicsScreenshoter();

	return 0;
}