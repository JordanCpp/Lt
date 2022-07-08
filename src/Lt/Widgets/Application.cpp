#include <Lt/Widgets/Application.hpp>
#include <Lt/Core/Ticks.hpp>

Lt::Widgets::Application::Application(Lt::Graphics::Window* window, Lt::Graphics::Render* render):
	Lt::Widgets::Widget(window, render, window->Pos(), window->Size()),
	_Window(window),
	_Render(render)
{
}

void Lt::Widgets::Application::Draw()
{
	for (Lt::usize i = 0; i < Widgets().Length(); i++)
	{
		Widgets()[i]->Draw();
	}
}

void Lt::Widgets::Application::Run()
{
	Lt::Events::Event event;

	while (_Window->GetEvent(event))
	{
		Draw();

		_Render->Present();

		Lt::Core::Delay(5);
	}
}