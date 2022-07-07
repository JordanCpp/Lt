#include <Lt/Widgets/Application.hpp>

Lt::Widgets::Application::Application(Lt::Graphics::Window* window, Lt::Graphics::Render* render):
	_Window(window),
	_Render(render)
{
}

void Lt::Widgets::Application::Run()
{
	Lt::Events::Event event;

	while (_Window->GetEvent(event))
	{
		_Render->Present();
	}
}