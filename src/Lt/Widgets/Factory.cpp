#include <Lt/Widgets/Factory.hpp>

Lt::Widgets::Factory::Factory(Lt::Graphics::Window* window, Lt::Graphics::Render* render):
	_Window(window),
	_Render(render)
{
}

Lt::Widgets::Factory::~Factory()
{
	for (Lt::usize i = 0; i < _Widgets.Length(); i++)
	{
		delete _Widgets[i];
	}
}

const Lt::Graphics::Window* Lt::Widgets::Factory::Window()
{
	return _Window;
}

const Lt::Graphics::Render* Lt::Widgets::Factory::Render()
{
	return _Render;
}

const Lt::Containers::Vector<Lt::Widgets::Widget*> Lt::Widgets::Factory::Widgets()
{
	return _Widgets;
}

Lt::Widgets::Button* Lt::Widgets::Factory::Button(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	Lt::Widgets::Button* result = new Lt::Widgets::Button(_Window, _Render, pos, size);

	_Widgets.Append(result);

	return result;
}