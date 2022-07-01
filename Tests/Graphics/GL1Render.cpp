#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/GL1/GL1Render.hpp>

void TestGraphicsGL1Render()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	LT_TEST_EQUAL(errorHandler.IsError() == false);

	Lt::Graphics::GL1Render render(errorHandler, &window);
	LT_TEST_EQUAL(errorHandler.IsError() == false);

	LT_TEST_EQUAL(render.Size().PosX() == 800);
	LT_TEST_EQUAL(render.Size().PosY() == 600);

	render.Color(Lt::Graphics::Color(15, 20, 25, 100));

	LT_TEST_EQUAL(render.Color().Red() == 15);
	LT_TEST_EQUAL(render.Color().Green() == 20);
	LT_TEST_EQUAL(render.Color().Blue() == 25);
	LT_TEST_EQUAL(render.Color().Alpha() == 100);
}

int main()
{
	TestGraphicsGL1Render();

	return 0;
}