#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuWindow.hpp>

void TestGraphicscpuWindow()
{
	Lt::Graphics::CpuWindow cpuWindow(Lt::Graphics::Point2i(0, 0), Lt::Graphics::Point2i(800, 600), "Window!");

	LT_TEST_EQUAL(cpuWindow.IsError() == false);
}
int main()
{
	TestGraphicscpuWindow();

	return 0;
}