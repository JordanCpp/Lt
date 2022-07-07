#include <Lt/Widgets/Button.hpp>

Lt::Widgets::Button::Button(Lt::Graphics::Window* window, Lt::Graphics::Render* render, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size):
	Lt::Widgets::Widget(window, render, pos, size)
{
}

void Lt::Widgets::Button::Draw()
{
	Render()->Color(Lt::Graphics::Color(244, 244, 244));
	Render()->Fill(Pos(), Size());
}
