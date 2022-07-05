#include <Lt/View/ColorRect.hpp>

Lt::View::ColorRect::ColorRect(Lt::Graphics::Color& color, Lt::Graphics::Point2u& pos, Lt::Graphics::Point2u& size):
	_Color(color),
	_Rect(pos, size)
{
}