#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Screenshoter.hpp>
#include <Lt/Core/BinaryFile.hpp>

void TestGraphicsScreenshoter()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(&errorHandler, &window);
	Lt::Graphics::Screenshoter screenshoter(&render, "TestFiles/");
	Lt::Core::BinaryFile binaryFile;

	render.Color(Lt::Graphics::Color(237, 28, 36));
	render.Clear();

	screenshoter.Shot();

	LT_TEST_EQUAL(binaryFile.Exist(screenshoter.Path()) == true);
	LT_TEST_EQUAL(binaryFile.Delete(screenshoter.Path()) == true);
}

int main()
{
	TestGraphicsScreenshoter();

	return 0;
}