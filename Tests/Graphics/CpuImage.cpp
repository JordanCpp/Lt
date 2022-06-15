#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuImage.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsCpuImageInit()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::FixedLinear::Mb * 4);

	Lt::Graphics::CpuImage cpuImage(Lt::Graphics::Point2i(800, 600), &allocator);

	LT_TEST_EQUAL(cpuImage.Size().PosX() == 800);
	LT_TEST_EQUAL(cpuImage.Size().PosY() == 600);
	LT_TEST_EQUAL(cpuImage.Channels() == 4);
	LT_TEST_EQUAL(cpuImage.Allocator() == &allocator);
	LT_TEST_EQUAL(cpuImage.Pixels() != nullptr);
}

int main()
{
	TestGraphicsCpuImageInit();

	return 0;
}