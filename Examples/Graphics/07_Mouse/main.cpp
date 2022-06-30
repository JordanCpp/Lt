#include <Lt/Graphics/Render.hpp>
#include <Lt/Graphics/FpsLimiter.hpp>
#include <Lt/Core/Console.hpp>
#include <Lt/Graphics/FpsCounter.hpp>

void ShowError(const Lt::Core::ErrorHandler& errorHandler)
{
	Lt::Core::Console console;

	console.Write(errorHandler.Message());
	console.Show();
}

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	if (errorHandler.IsError())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Graphics::Render render(errorHandler, &window);

	if (errorHandler.IsError())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Events::Event report;

	Lt::Graphics::FpsCounter fpsCounter;
	Lt::Core::IntegerToString integerToString;

	Lt::usize x = 0;
	Lt::usize y = 0;

	while (window.GetEvent(report))
	{
		render.Color(Lt::Graphics::Color(195, 195, 195));
		render.Clear();

		if (report.Type == Lt::Events::IsQuit)
		{
			window.StopEvent();
		}

		if (report.Type == Lt::Events::IsMouseMove)
		{
			x = report.Mouse.PosX;
			y = report.Mouse.PosY;
		}

		render.Color(Lt::Graphics::Color(237, 28, 36));
		render.FillRect(Lt::Graphics::Point2u(x - 100, y - 100), Lt::Graphics::Point2u(100, 100));

		render.Present();

		if (fpsCounter.Calc())
		{
			if (integerToString.Convert(fpsCounter.Fps()))
			{
				window.Title(integerToString.Result());
			}

			fpsCounter.Clear();
		}
	}

	return 0;
}