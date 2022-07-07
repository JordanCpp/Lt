#include <Lt/Widgets/Application.hpp>

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::GL1Window window(errorHandler, Lt::Graphics::Point2u(25, 50), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::GL1Render render(errorHandler, &window);

	Lt::Widgets::Application application(&window, &render);

	application.Run();

	return 0;
}