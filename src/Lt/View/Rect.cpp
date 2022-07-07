#include <Lt/View/Rect.hpp>

Lt::View::Rect::Rect(Lt::Graphics::Color& color, Lt::Graphics::Point2u& pos, Lt::Graphics::Point2u& size):
	_Color(color),
	_Rect(pos, size)
{
}