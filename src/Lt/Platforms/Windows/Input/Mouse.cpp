#include <Lt/Input/Mouse.hpp>
#include <Windows.h>

const Lt::Graphics::Point2u& Lt::Input::Mouse::Pos()
{
	POINT point;
	
	GetCursorPos(&point);

	_Pos = Lt::Graphics::Point2u(point.x, point.y);

	return _Pos;
}
