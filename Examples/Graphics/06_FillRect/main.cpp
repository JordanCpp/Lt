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

	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	if (errorHandler.IsError())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Graphics::Render render(&errorHandler, &window);

	if (errorHandler.IsError())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Events::Event report;

	Lt::Graphics::FpsCounter fpsCounter;
	Lt::Core::IntegerToString integerToString;

	while (window.GetEvent(report))
	{
		render.Color(Lt::Graphics::Color(195, 195, 195));
		render.Clear();

		if (report.Type == Lt::Events::IsQuit)
		{
			window.StopEvent();
		}

		render.Color(Lt::Graphics::Color(237, 28, 36));
		render.Fill(Lt::Graphics::Point2u(100, 100), Lt::Graphics::Point2u(300, 300));

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