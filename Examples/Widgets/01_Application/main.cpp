#include <Lt/Widgets/Application.hpp>
#include <Lt/Widgets/Factory.hpp>

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(errorHandler, &window);

	Lt::Widgets::Factory factory(&window, &render);

	Lt::Widgets::Application application(&window, &render);

	Lt::Widgets::Button* button = factory.Button(Lt::Graphics::Point2u(5, 5), Lt::Graphics::Point2u(145, 45));

	application.Attach(button);

	application.Run();

	return 0;
}