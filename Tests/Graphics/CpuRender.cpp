#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuRender.hpp>

void TestGraphicsCpuRender()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::CpuWindow window(errorHandler, Lt::Graphics::Point2i(25, 50), Lt::Graphics::Point2i(800, 600), "Window!");

	Lt::Graphics::CpuRender render(&window);

	LT_TEST_EQUAL(render.Size().PosX() == 800);
	LT_TEST_EQUAL(render.Size().PosY() == 600);
	LT_TEST_EQUAL(render.Canvas() != nullptr);

	render.Color(Lt::Graphics::Color(15, 20, 25, 100));

	LT_TEST_EQUAL(render.Color().Red() == 15);
	LT_TEST_EQUAL(render.Color().Green() == 20);
	LT_TEST_EQUAL(render.Color().Blue() == 25);
	LT_TEST_EQUAL(render.Color().Alpha() == 100);
}

void TestGraphicsCpuClear()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Graphics::CpuWindow window(errorHandler, Lt::Graphics::Point2i(25, 50), Lt::Graphics::Point2i(800, 600), "Window!");
	Lt::Graphics::CpuRender render(&window);

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

int main()
{
	TestGraphicsCpuRender();
	TestGraphicsCpuClear();

	return 0;
}