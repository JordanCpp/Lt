#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Render.hpp>

void TestGraphicsCpuRender()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(&errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.Error() == false);
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
	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(&errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.Error() == false);

	Lt::Graphics::Color color(15, 25, 35, 45);

	render.Color(color);
	render.Clear();

	Lt::usize x = 0;
	Lt::usize y = 0;

	for (Lt::usize i = 0; i < render.Size().PosX(); i++)
	{
		for (Lt::usize j = 0; j < render.Size().PosY(); j++)
		{
			Lt::Graphics::Color pixel = render.GetPixel(Lt::Graphics::Point2u(x + i, y + j));

			LT_TEST_EQUAL(pixel.Red() == color.Red());
			LT_TEST_EQUAL(pixel.Green() == color.Green());
			LT_TEST_EQUAL(pixel.Blue() == color.Blue());
			LT_TEST_EQUAL(pixel.Alpha() == color.Alpha());
		}
	}
}

void TestGraphicsCpuRenderPixel()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(&errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.Error() == false);

	Lt::Graphics::Color color(15, 25, 35, 45);
	Lt::Graphics::Point2u point(150, 235);

	render.Color(color);
	render.Pixel(point);

	LT_TEST_EQUAL(render.GetPixel(point).Red() == color.Red());
	LT_TEST_EQUAL(render.GetPixel(point).Green() == color.Green());
	LT_TEST_EQUAL(render.GetPixel(point).Blue() == color.Blue());
	LT_TEST_EQUAL(render.GetPixel(point).Alpha() == color.Alpha());
}

void TestGraphicsCpuRenderFillRect()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(800, 600), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(&errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.Error() == false);

	Lt::Graphics::Color color(15, 25, 35, 45);

	Lt::Graphics::Point2u pos(150, 200);
	Lt::Graphics::Point2u size(250, 345);

	render.Color(color);
	render.Fill(pos, size);

	Lt::usize x = pos.PosX();
	Lt::usize y = pos.PosY();

	for (Lt::usize i = 0; i < size.PosX(); i++)
	{
		for (Lt::usize j = 0; j < size.PosY(); j++)
		{
			Lt::Graphics::Color pixel = render.GetPixel(Lt::Graphics::Point2u(x + i, y + j));

			LT_TEST_EQUAL(pixel.Red() == color.Red());
			LT_TEST_EQUAL(pixel.Green() == color.Green());
			LT_TEST_EQUAL(pixel.Blue() == color.Blue());
			LT_TEST_EQUAL(pixel.Alpha() == color.Alpha());
		}
	}
}

void TestGraphicsCpuRenderLine()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(800, 600), Lt::Graphics::Point2u(800, 600), "Window!");
	Lt::Graphics::Render render(&errorHandler, &window);

	LT_TEST_EQUAL(errorHandler.Error() == false);

	Lt::Graphics::Color color(15, 25, 35, 45);

	Lt::Graphics::Point2u pos1(0, 0);
	Lt::Graphics::Point2u pos2(100, 0);

	render.Color(color);
	render.Line(pos1, pos2);

	Lt::usize x = pos1.PosX();
	Lt::usize y = pos1.PosY();

	for (Lt::usize i = 0; i < pos2.PosX(); i++)
	{
		for (Lt::usize j = 0; j < pos2.PosY(); j++)
		{
			Lt::Graphics::Color pixel = render.GetPixel(Lt::Graphics::Point2u(x + i, y + j));

			LT_TEST_EQUAL(pixel.Red() == color.Red());
			LT_TEST_EQUAL(pixel.Green() == color.Green());
			LT_TEST_EQUAL(pixel.Blue() == color.Blue());
			LT_TEST_EQUAL(pixel.Alpha() == color.Alpha());
		}
	}
}

int main()
{
	TestGraphicsCpuRender();
	TestGraphicsCpuRenderClear();
	TestGraphicsCpuRenderPixel();
	TestGraphicsCpuRenderFillRect();
	TestGraphicsCpuRenderLine();

	return 0;
}