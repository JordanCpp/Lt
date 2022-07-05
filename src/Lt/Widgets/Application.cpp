#include <Lt/Widgets/Application.hpp>

Lt::Widgets::Application::Application():
	_Window(_ErrorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), ""),
	_Render(_ErrorHandler, &_Window)
{
}

void Lt::Widgets::Application::Run()
{
	Lt::Events::Event event;

	while (_Window.GetEvent(event))
	{
	}
}