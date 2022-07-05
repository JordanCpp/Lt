#include <Lt/Widgets/Container.hpp>

Lt::Widgets::Container::Container(Lt::Widgets::Widget* parent):
	_Parent(parent)
{
}

const Lt::Containers::Vector<Lt::Widgets::Widget*>& Lt::Widgets::Container::Widgets()
{
	return _Widgets;
}