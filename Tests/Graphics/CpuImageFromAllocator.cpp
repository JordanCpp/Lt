#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuImageFromAllocator.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsCpuImageFromAllocatorInit()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::FixedLinear::Mb * 4);

	Lt::Graphics::CpuImageFromAllocator cpuImageFromMemory(4, Lt::Graphics::Point2u(800, 600), &allocator);

	LT_TEST_EQUAL(allocator.UsedBytes() == 800 * 600 * 4);
	LT_TEST_EQUAL(cpuImageFromMemory.Size().PosX() == 800);
	LT_TEST_EQUAL(cpuImageFromMemory.Size().PosY() == 600);
	LT_TEST_EQUAL(cpuImageFromMemory.Channels() == 4);
	LT_TEST_EQUAL(cpuImageFromMemory.Allocator() == &allocator);
	LT_TEST_EQUAL(cpuImageFromMemory.Pixels() != nullptr);
}

int main()
{
	TestGraphicsCpuImageFromAllocatorInit();

	return 0;
}