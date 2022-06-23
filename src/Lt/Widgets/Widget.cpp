#include <Lt/Widgets/Widget.hpp>

Lt::Widgets::Widget::Widget(Lt::Graphics::Window* window, Lt::Graphics::Render* render, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size):
	_Action(nullptr),
	_Parent(nullptr),
	_Window(window),
	_Render(render),
	_Area(pos, size)
{
}

Lt::Widgets::Widget::~Widget()
{
}

const Lt::Graphics::Point2u& Lt::Widgets::Widget::Pos()
{
	return _Area.Pos();
}

const Lt::Graphics::Point2u& Lt::Widgets::Widget::Size()
{
	return _Area.Size();
}

const Lt::Graphics::Window* Lt::Widgets::Widget::Window()
{
	return _Window;
}

const Lt::Graphics::Render* Lt::Widgets::Widget::Render()
{
	return _Render;
}

const Lt::Widgets::Widget* Lt::Widgets::Widget::Parent()
{
	return _Parent;
}

void Lt::Widgets::Widget::Parent(Lt::Widgets::Widget* widget)
{
	_Parent = widget;
}

void Lt::Widgets::Widget::Attach(Lt::Widgets::Widget* widget)
{
	widget->Parent(this);

	_Widgets.Append(widget);
}

Lt::Widgets::Widget::ActionCallback Lt::Widgets::Widget::Action()
{
	return _Action;
}

void Lt::Widgets::Widget::Action(Lt::Widgets::Widget::ActionCallback actionCallback)
{
	_Action = actionCallback;
}

void Lt::Widgets::Widget::Action(Lt::Widgets::Widget* source, Lt::usize type, void* content)
{
	if (_Action != nullptr)
	{
		_Action(source, type, content);
	}
}