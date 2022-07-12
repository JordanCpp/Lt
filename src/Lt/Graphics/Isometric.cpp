#include <Lt/Graphics/Isometric.hpp>

const Lt::Graphics::Point2u& Lt::Graphics::Isometric::CartesianToIsometric(const Lt::Graphics::Point2u& pt)
{
	size_t x = pt.PosX() - pt.PosY();
	size_t y = (pt.PosX() + pt.PosY()) / 2;

	_Current.Pos(x, y);

	return _Current;
}

const Lt::Graphics::Point2u& Lt::Graphics::Isometric::IsometricToCartesian(const Lt::Graphics::Point2u& pt)
{
	size_t x = (2 * pt.PosY() + pt.PosX()) / 2;
	size_t y = (2 * pt.PosY() - pt.PosX()) / 2;

	_Current.Pos(x, y);

	return _Current;
}