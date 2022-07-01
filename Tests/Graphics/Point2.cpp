#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Primitives/Point2u.hpp>
#include <Lt/Graphics/Primitives/Point2i.hpp>

void TestGraphicsPoint2u()
{
	Lt::Graphics::Point2u point;

	LT_TEST_EQUAL(point.PosX() == 0);
	LT_TEST_EQUAL(point.PosY() == 0);

	Lt::Graphics::Point2u point2(125, 385);

	LT_TEST_EQUAL(point2.PosX() == 125);
	LT_TEST_EQUAL(point2.PosY() == 385);
}

void TestGraphicsPoint2i()
{
	Lt::Graphics::Point2i point;

	LT_TEST_EQUAL(point.PosX() == 0);
	LT_TEST_EQUAL(point.PosY() == 0);

	Lt::Graphics::Point2i point2(125, 385);

	LT_TEST_EQUAL(point2.PosX() == 125);
	LT_TEST_EQUAL(point2.PosY() == 385);
}

int main()
{
	TestGraphicsPoint2u();
	TestGraphicsPoint2i();

	return 0;
}