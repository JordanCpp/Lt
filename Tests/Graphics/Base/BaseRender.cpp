#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Base/BaseRender.hpp>

void TestGraphicsBaseRenderInit()
{
	Lt::Graphics::BaseRender baseRender(Lt::Graphics::Point2u(800, 600));

	LT_TEST_EQUAL(baseRender.Size().PosX() == 800);
	LT_TEST_EQUAL(baseRender.Size().PosY() == 600);

	LT_TEST_EQUAL(baseRender.Color().Red() == 0);
	LT_TEST_EQUAL(baseRender.Color().Green() == 0);
	LT_TEST_EQUAL(baseRender.Color().Blue() == 0);
	LT_TEST_EQUAL(baseRender.Color().Alpha() == 255);
}

void TestGraphicsBaseRenderColor()
{
	Lt::Graphics::BaseRender baseRender(Lt::Graphics::Point2u(800, 600));

	baseRender.Color(Lt::Graphics::Color(125, 175, 235));

	LT_TEST_EQUAL(baseRender.Size().PosX() == 800);
	LT_TEST_EQUAL(baseRender.Size().PosY() == 600);

	LT_TEST_EQUAL(baseRender.Color().Red() == 125);
	LT_TEST_EQUAL(baseRender.Color().Green() == 175);
	LT_TEST_EQUAL(baseRender.Color().Blue() == 235);
	LT_TEST_EQUAL(baseRender.Color().Alpha() == 255);
}

int main()
{
	TestGraphicsBaseRenderInit();
	TestGraphicsBaseRenderColor();

	return 0;
}