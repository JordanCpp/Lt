#include <Lt/Widgets/Application.hpp>
#include <Lt/Widgets/Factory.hpp>
#include <Lt/Core/Console.hpp>

int main()
{
	Lt::Core::Console io;

	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");
	
	if (errorHandler.IsOk())
	{
		Lt::Graphics::Render render(&errorHandler, &window);

		if (errorHandler.IsOk())
		{
			Lt::Widgets::Factory factory(&window, &render);

			Lt::Widgets::Application application(&window, &render);

			Lt::Widgets::Button* button = factory.Button(Lt::Graphics::Point2u(5, 5), Lt::Graphics::Point2u(145, 35));

			application.Attach(button);

			application.Run();
		}
	}
	
	if (errorHandler.IsError())
	{
		io.Write(errorHandler.Message());
		io.Show();
	}

	return 0;
}