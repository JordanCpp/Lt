#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuWindow.hpp>

void TestGraphicscpuWindow()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::CpuWindow cpuWindow(errorHandler, Lt::Graphics::Point2i(0, 0), Lt::Graphics::Point2i(800, 600), "Window!");

	LT_TEST_EQUAL(errorHandler.IsError() == false);
}
int main()
{
	TestGraphicscpuWindow();

	return 0;
}