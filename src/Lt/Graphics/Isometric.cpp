#include <Lt/Graphics/Isometric.hpp>

const Lt::Graphics::Point2u& Lt::Graphics::Isometric::CartesianToIsometric(const Lt::Graphics::Point2u& pt)
{
	Lt::usize x = pt.PosX() - pt.PosY();
	Lt::usize y = (pt.PosX() + pt.PosY()) / 2;

	_Current.Pos(x, y);

	return _Current;
}

const Lt::Graphics::Point2u& Lt::Graphics::Isometric::IsometricToCartesian(const Lt::Graphics::Point2u& pt)
{
	Lt::usize x = (2 * pt.PosY() + pt.PosX()) / 2;
	Lt::usize y = (2 * pt.PosY() - pt.PosX()) / 2;

	_Current.Pos(x, y);

	return _Current;
}