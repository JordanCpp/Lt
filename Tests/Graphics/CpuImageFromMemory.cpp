#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuImageFromMemory.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsCpuImageFromMemoryInit()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::FixedLinear::Mb * 4);

	Lt::u8* src = (Lt::u8*)allocator.Allocate(1024);
	Lt::Graphics::CpuImageFromMemory cpuImageFromMemory(4, Lt::Graphics::Point2u(800, 600), src);

	LT_TEST_EQUAL(cpuImageFromMemory.Size().PosX() == 800);
	LT_TEST_EQUAL(cpuImageFromMemory.Size().PosY() == 600);
	LT_TEST_EQUAL(cpuImageFromMemory.Channels() == 4);
	LT_TEST_EQUAL(cpuImageFromMemory.Pixels() == src);
}

int main()
{
	TestGraphicsCpuImageFromMemoryInit();

	return 0;
}