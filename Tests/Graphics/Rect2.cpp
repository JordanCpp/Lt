#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Point2i.hpp>
#include <Lt/Graphics/Point2u.hpp>
#include <Lt/Graphics/Rect2i.hpp>
#include <Lt/Graphics/Rect2u.hpp>

void TestGraphicsRect2u()
{
	Lt::Graphics::Rect2i rect;

	LT_TEST_EQUAL(rect.Pos().PosX() == 0);
	LT_TEST_EQUAL(rect.Pos().PosY() == 0);
	LT_TEST_EQUAL(rect.Size().PosX() == 0);
	LT_TEST_EQUAL(rect.Size().PosY() == 0);

	Lt::Graphics::Rect2i rect2(15, 25, 35, 45);

	LT_TEST_EQUAL(rect2.Pos().PosX() == 15);
	LT_TEST_EQUAL(rect2.Pos().PosY() == 25);
	LT_TEST_EQUAL(rect2.Size().PosX() == 35);
	LT_TEST_EQUAL(rect2.Size().PosY() == 45);

	Lt::Graphics::Rect2i rect3(Lt::Graphics::Point2i(115, 125), Lt::Graphics::Point2i(135, 145));

	LT_TEST_EQUAL(rect3.Pos().PosX() == 115);
	LT_TEST_EQUAL(rect3.Pos().PosY() == 125);
	LT_TEST_EQUAL(rect3.Size().PosX() == 135);
	LT_TEST_EQUAL(rect3.Size().PosY() == 145);
}

void TestGraphicsRect2i()
{
	Lt::Graphics::Rect2u rect;

	LT_TEST_EQUAL(rect.Pos().PosX() == 0);
	LT_TEST_EQUAL(rect.Pos().PosY() == 0);
	LT_TEST_EQUAL(rect.Size().PosX() == 0);
	LT_TEST_EQUAL(rect.Size().PosY() == 0);

	Lt::Graphics::Rect2u rect2(15, 25, 35, 45);

	LT_TEST_EQUAL(rect2.Pos().PosX() == 15);
	LT_TEST_EQUAL(rect2.Pos().PosY() == 25);
	LT_TEST_EQUAL(rect2.Size().PosX() == 35);
	LT_TEST_EQUAL(rect2.Size().PosY() == 45);

	Lt::Graphics::Rect2u rect3(Lt::Graphics::Point2u(115, 125), Lt::Graphics::Point2u(135, 145));

	LT_TEST_EQUAL(rect3.Pos().PosX() == 115);
	LT_TEST_EQUAL(rect3.Pos().PosY() == 125);
	LT_TEST_EQUAL(rect3.Size().PosX() == 135);
	LT_TEST_EQUAL(rect3.Size().PosY() == 145);
}

int main()
{
	TestGraphicsRect2u();
	TestGraphicsRect2i();

	return 0;
}