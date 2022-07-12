#include <Lt/Graphics/Render.hpp>
#include <Lt/Graphics/FpsLimiter.hpp>
#include <Lt/Core/Console.hpp>

void ShowError(const Lt::Core::ErrorHandler& errorHandler)
{
	Lt::Core::Console console;

	console.Write(errorHandler.Message());
	console.Show();
}

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	if (errorHandler.Error())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Graphics::Render render(&errorHandler, &window);

	if (errorHandler.Error())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Events::Event report;

	Lt::usize x = 0;
	Lt::usize y = 0;

	while (window.WaitEvent(report))
	{
		if (errorHandler.Error())
			window.StopEvent();

		render.Color(Lt::Graphics::Color(237, 28, 36));
		render.Clear();

		if (report.Type == Lt::Events::IsQuit)
		{
			window.StopEvent();
		}

		if (report.Type == Lt::Events::IsMouseClick)
		{
			x = report.Mouse.PosX;
			y = report.Mouse.PosY;
		}

		render.Color(Lt::Graphics::Color(34, 177, 76));
		render.Fill(Lt::Graphics::Point2u(x, y), Lt::Graphics::Point2u(100, 100));

		render.Present();
	}

	return 0;
}