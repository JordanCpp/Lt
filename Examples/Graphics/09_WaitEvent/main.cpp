#include <Lt/Graphics/Render.hpp>
#include <Lt/Graphics/FpsLimiter.hpp>
#include <Lt/Core/Console.hpp>
#include <Lt/Graphics/Primitives/Rect2u.hpp>
#include <Lt/Containers/Vector.hpp>

void ShowError(const Lt::Core::ErrorHandler& errorHandler)
{
	Lt::Core::Console console;

	console.Write(errorHandler.Message());
	console.Show();
}

struct Rect
{
	Lt::Graphics::Rect2u size;
	Lt::Graphics::Color color;
};
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

	render.Color(Lt::Graphics::Color(237, 28, 36));
	render.Clear();
	render.Present();


	Lt::Containers::Vector<Rect> rects;

	while (window.WaitEvent(report))
	{
		if (errorHandler.Error())
			window.StopEvent();

		if (report.Type == Lt::Events::IsQuit)
		{
			window.StopEvent();
		}

		if (report.Type == Lt::Events::IsMouseClick)
		{
			x = report.Mouse.PosX;
			y = report.Mouse.PosY;

			Rect rect;
			rect.color = Lt::Graphics::Color(34, 177, 76);
			rect.size.Pos(x, y);
			rect.size.Size(50, 50);
			rects.Append(rect);

			render.Color(Lt::Graphics::Color(237, 28, 36));
			render.Clear();


			for (Lt::usize i = 0; i < rects.Length(); i++)
			{
				render.Color(rects[i].color);
				render.Fill(rects[i].size.Pos(), rects[i].size.Size());
			}

			render.Present();
		}
	}

	return 0;
}