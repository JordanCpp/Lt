#include <Lt/View/Line.hpp>

Lt::View::Line::Line(const Lt::Graphics::Color& color, const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2) :
	_Color(color),
	_Pos1(pos1),
	_Pos2(pos2)
{
}