#include <Lt/Core/TestEqual.hpp>
#include <Lt/Widgets/Factory.hpp>

void TestWidgetsFactory()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(errorHandler, &window);

	Lt::Widgets::Factory factory(&window, &render);
}

int main()
{
	TestWidgetsFactory();

	return 0;
}