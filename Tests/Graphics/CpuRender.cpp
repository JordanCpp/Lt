#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Render.hpp>

void TestGraphicsCpuRender()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(render.Size().PosX() == 800);
	LT_TEST_EQUAL(render.Size().PosY() == 600);
	LT_TEST_EQUAL(render.Canvas() != nullptr);

	render.Color(Lt::Graphics::Color(15, 20, 25, 100));

	LT_TEST_EQUAL(render.Color().Red() == 15);
	LT_TEST_EQUAL(render.Color().Green() == 20);
	LT_TEST_EQUAL(render.Color().Blue() == 25);
	LT_TEST_EQUAL(render.Color().Alpha() == 100);
}

void TestGraphicsCpuRenderClear()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.IsError() == false);

	render.Clear();

	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)render.Canvas()->Pixels();

	render.Color(Lt::Graphics::Color(15, 25, 35, 45));

	for (Lt::usize i = 0; i < render.Size().PosX() * render.Size().PosY(); i++)
	{
		LT_TEST_EQUAL(render.Color().Red() == 15);
		LT_TEST_EQUAL(render.Color().Green() == 25);
		LT_TEST_EQUAL(render.Color().Blue() == 35);
		LT_TEST_EQUAL(render.Color().Alpha() == 45);
	}
}

void TestGraphicsCpuRenderPixel()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.IsError() == false);

	Lt::Graphics::Color color(15, 25, 35, 45);
	Lt::Graphics::Point2u point(150, 235);

	render.Color(color);
	render.Pixel(point);

	LT_TEST_EQUAL(render.GetPixel(point).Red() == color.Red());
	LT_TEST_EQUAL(render.GetPixel(point).Green() == color.Green());
	LT_TEST_EQUAL(render.GetPixel(point).Blue() == color.Blue());
	LT_TEST_EQUAL(render.GetPixel(point).Alpha() == color.Alpha());
}

int main()
{
	TestGraphicsCpuRender();
	TestGraphicsCpuRenderClear();
	TestGraphicsCpuRenderPixel();

	return 0;
}