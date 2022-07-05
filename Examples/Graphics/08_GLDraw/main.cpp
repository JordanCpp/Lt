#include <Lt/Graphics/GL1/GL1Render.hpp>
#include <Lt/Graphics/FpsLimiter.hpp>
#include <Lt/Core/Console.hpp>
#include <Lt/Graphics/FpsCounter.hpp>
#include <Lt/Managers/PathManager.hpp>
#include <Lt/Allocators/FixedLinear.hpp>
#include <Lt/Loaders/ImageLoader.hpp>
#include <Lt/Factories/ImageFactory.hpp>
#include <Lt/Managers/ImageManager.hpp>

void ShowError(const Lt::Core::ErrorHandler& errorHandler)
{
	Lt::Core::Console console;

	console.Write(errorHandler.Message());
	console.Show();
}

int main()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Point2u resolution(800, 600);

	Lt::Graphics::GL1Window window(errorHandler, Lt::Graphics::Point2u(0, 0), resolution, "GLDraw");

	if (errorHandler.IsError())
	{
		ShowError(errorHandler);

		return 0;
	}

	Lt::Graphics::GL1Render render(errorHandler, &window);

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

	Lt::Managers::PathManager path("TestFiles/");

	Lt::Allocators::FixedLinear forLoader(Lt::Allocators::Allocator::Mb * 1);
	Lt::Allocators::FixedLinear forManager(Lt::Allocators::Allocator::Mb * 4);

	Lt::Loaders::ImageLoader loader(&errorHandler, &forLoader);

	Lt::Factories::ImageFactory factory(&forManager, &loader);

	Lt::Managers::ImageManager manager(&path, &factory);

	Lt::Graphics::CpuImage* image = manager.Get("", "1182.jpg");

	Lt::Graphics::GL1Image texture(image);

	while (window.GetEvent(report))
	{
		if (report.Type == Lt::Events::IsMouseMove)
		{
			x = report.Mouse.PosX;
			y = report.Mouse.PosY;
		}

		render.Color(Lt::Graphics::Color(195, 195, 195));
		render.Clear();

		render.Draw(&texture, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(x, y));

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