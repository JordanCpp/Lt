#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Monitor.hpp>

void TestGraphicsMonitor()
{
	Lt::Graphics::Monitor monitor;

	LT_TEST_EQUAL(monitor.Resolution().PosX() > 0);
	LT_TEST_EQUAL(monitor.Resolution().PosY() > 0);
	LT_TEST_EQUAL(monitor.Resolution().PosX() > monitor.Resolution().PosY());
}

int main()
{
	TestGraphicsMonitor();

	return 0;
}