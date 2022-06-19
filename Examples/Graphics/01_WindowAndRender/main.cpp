#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Render.hpp>

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::CpuWindow window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

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

	return 0;
}