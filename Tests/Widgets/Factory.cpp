#include <Lt/Core/TestEqual.hpp>
#include <Lt/Widgets/Factory.hpp>

void TestWidgetsFactory()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(errorHandler, &window);

	Lt::Widgets::Factory factory(&window, &render);

	LT_TEST_EQUAL(factory.Window() == &window);
	LT_TEST_EQUAL(factory.Render() == &render);

	LT_TEST_EQUAL(factory.Widgets().Length() == 0);

	Lt::Widgets::Widget* widget = factory.Button(Lt::Graphics::Point2u(10, 15), Lt::Graphics::Point2u(100, 25));

	LT_TEST_EQUAL(factory.Widgets().Length() == 1);
	LT_TEST_EQUAL(factory.Widgets()[0] == widget);
}

int main()
{
	TestWidgetsFactory();

	return 0;
}