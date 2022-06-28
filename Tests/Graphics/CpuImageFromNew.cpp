#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuImageFromNew.hpp>

void TestGraphicsCpuImageFromNewInit()
{
	Lt::Graphics::CpuImageFromNew cpuImageFromNew(4, Lt::Graphics::Point2u(800, 600));

	LT_TEST_EQUAL(cpuImageFromNew.Size().PosX() == 800);
	LT_TEST_EQUAL(cpuImageFromNew.Size().PosY() == 600);
	LT_TEST_EQUAL(cpuImageFromNew.Channels() == 4);
	LT_TEST_EQUAL(cpuImageFromNew.Pixels() != nullptr);
}

int main()
{
	TestGraphicsCpuImageFromNewInit();

	return 0;
}