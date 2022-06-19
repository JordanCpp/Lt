#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Render.hpp>
#include <Lt/Core/Console.hpp>

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	if (errorHandler.IsError())
	{
		Lt::Core::Console console;

		console.Write(errorHandler.Message());
		console.Show();
	}
	else
	{
		Lt::Graphics::Render render(&window);

		Lt::Events::Event report;

		while (window.GetEvent(report))
		{
			if (report.Type == Lt::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Present();
		}
	}

	return 0;
}