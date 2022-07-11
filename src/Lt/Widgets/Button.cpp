#include <Lt/Widgets/Button.hpp>

Lt::Widgets::Button::Button(Lt::Graphics::Window* window, Lt::Graphics::Render* render, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size):
	Lt::Widgets::Widget(window, render, pos, size),
	_Allocator(nullptr)
{
}

Lt::Widgets::Button::Button(Lt::Allocators::Allocator* allocator, Lt::Graphics::Window* window, Lt::Graphics::Render* render, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size):
	Lt::Widgets::Widget(window, render, pos, size),
	_Allocator(allocator),
	_Title(allocator)
{
}

void Lt::Widgets::Button::Draw()
{
	Render()->Color(Lt::Graphics::Color(244, 244, 244));
	Render()->Fill(Pos(), Size());
}