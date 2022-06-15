#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/BaseWindow.hpp>

void TestGraphicsBaseWindowInit()
{
	Lt::Graphics::BaseWindow baseWindow(Lt::Graphics::Point2i(25, 50), Lt::Graphics::Point2i(800, 600), "Hello world!");

	LT_TEST_EQUAL(baseWindow.Pos().PosX() == 25);
	LT_TEST_EQUAL(baseWindow.Pos().PosY() == 50);
	LT_TEST_EQUAL(baseWindow.Size().PosX() == 800);
	LT_TEST_EQUAL(baseWindow.Size().PosY() == 600);
	LT_TEST_EQUAL(Lt::Chars::Equal(baseWindow.Title(), "Hello world!") == true);
}

void TestGraphicsBaseWindowTitle()
{
	Lt::Graphics::BaseWindow baseWindow(Lt::Graphics::Point2i(25, 50), Lt::Graphics::Point2i(800, 600), "Hello!");

	baseWindow.Title("World!");

	LT_TEST_EQUAL(Lt::Chars::Equal(baseWindow.Title(), "World!") == true);
}

int main()
{
	TestGraphicsBaseWindowInit();
	TestGraphicsBaseWindowTitle();

	return 0;
}