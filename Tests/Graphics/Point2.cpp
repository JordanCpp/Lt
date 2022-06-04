#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Point2i.hpp>

int main()
{
	Lt::Graphics::Point2i point;

	LT_TEST_EQUAL(point.PosX() == 0);
	LT_TEST_EQUAL(point.PosY() == 0);

	Lt::Graphics::Point2i point2(125, 385);

	LT_TEST_EQUAL(point2.PosX() == 125);
	LT_TEST_EQUAL(point2.PosY() == 385);

	return 0;
}