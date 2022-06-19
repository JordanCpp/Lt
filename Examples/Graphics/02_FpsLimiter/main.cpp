#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Render.hpp>
#include <Lt/Graphics/FpsLimiter.hpp>

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(&window);

	Lt::Events::Event report;

	Lt::Graphics::FpsLimiter limiter;

	while (window.GetEvent(report))
	{
		limiter.Mark();

		if (report.Type == Lt::Events::IsQuit)
		{
			window.StopEvent();
		}

		render.Present();

		limiter.Throttle();
	}

	return 0;
}