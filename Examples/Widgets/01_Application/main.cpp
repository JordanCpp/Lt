#include <Lt/Widgets/Application.hpp>
#include <Lt/Widgets/Factory.hpp>
#include <Lt/Core/Console.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

int main()
{
	Lt::Core::Console io;

	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(&errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");
	
	if (errorHandler.Ok())
	{
		Lt::Graphics::Render render(&errorHandler, &window);

		if (errorHandler.Ok())
		{
			Lt::Allocators::FixedLinear allocator(Lt::Allocators::Allocator::Mb * 1);

			Lt::Widgets::Factory factory(&window, &render, &allocator);

			Lt::Widgets::Application application(&window, &render);

			Lt::usize x = 5;
			Lt::usize y = 5;
			Lt::usize w = 145;
			Lt::usize h = 35;

			for (Lt::usize i = 0; i < 5; i++)
			{
				Lt::Widgets::Button* button = factory.Button(Lt::Graphics::Point2u(x, y), Lt::Graphics::Point2u(w, h));

				application.Attach(button);

				y += h + 10;
			}

			io.Write(allocator.UsedBytes());
			io.Line();
			io.Show();

			application.Run();
		}
	}
	
	if (errorHandler.Error())
	{
		io.Write(errorHandler.Message());
		io.Show();
	}

	return 0;
}