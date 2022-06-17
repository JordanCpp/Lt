#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/CpuImage.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsCpuImageInit()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::FixedLinear::Mb * 4);

	Lt::Graphics::CpuImage cpuImage(Lt::Graphics::Point2u(800, 600), &allocator);

	LT_TEST_EQUAL(cpuImage.Size().PosX() == 800);
	LT_TEST_EQUAL(cpuImage.Size().PosY() == 600);
	LT_TEST_EQUAL(cpuImage.Channels() == 4);
	LT_TEST_EQUAL(cpuImage.Allocator() == &allocator);
	LT_TEST_EQUAL(cpuImage.Pixels() != nullptr);
}

void TestGraphicsCpuImageFrom()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::FixedLinear::Mb * 4);

	Lt::Graphics::CpuImage src(Lt::Graphics::Point2u(800, 600), &allocator);

	Lt::Graphics::CpuImage dst(Lt::Graphics::Point2u(800, 600), src.Pixels());

	LT_TEST_EQUAL(dst.Size().PosX() == 800);
	LT_TEST_EQUAL(dst.Size().PosY() == 600);
	LT_TEST_EQUAL(dst.Channels() == 4);
	LT_TEST_EQUAL(dst.Allocator() == nullptr);
	LT_TEST_EQUAL(dst.Pixels() == src.Pixels());
}

int main()
{
	TestGraphicsCpuImageInit();
	TestGraphicsCpuImageFrom();

	return 0;
}