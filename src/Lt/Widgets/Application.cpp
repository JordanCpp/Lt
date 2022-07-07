#include <Lt/Widgets/Application.hpp>

Lt::Widgets::Application::Application(Lt::Graphics::Window* window, Lt::Graphics::Render* render):
	Lt::Widgets::Widget(window, render, window->Pos(), window->Size()),
	_Window(window),
	_Render(render)
{
}

void Lt::Widgets::Application::Draw()
{
}

void Lt::Widgets::Application::Run()
{
	Lt::Events::Event event;

	while (_Window->GetEvent(event))
	{
		for (Lt::usize i = 0; i < Widgets().Length(); i++)
		{
			Widgets()[i]->Draw();
		}

		_Render->Present();
	}
}