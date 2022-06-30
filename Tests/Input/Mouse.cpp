#include <Lt/Core/TestEqual.hpp>
#include <Lt/Input/Mouse.hpp>

void TestInputMouse()
{
	Lt::Input::Mouse mouse;

	LT_TEST_EQUAL(mouse.Pos().PosX() > 0);
	LT_TEST_EQUAL(mouse.Pos().PosY() > 0);
}

int main()
{
	TestInputMouse();

	return 0;
}