#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/BaseCpuImage.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsBaseCpuImageInit()
{
	Lt::Graphics::BaseCpuImage baseCpuImage(4, Lt::Graphics::Point2u(800, 600), nullptr);

	LT_TEST_EQUAL(baseCpuImage.Size().PosX() == 800);
	LT_TEST_EQUAL(baseCpuImage.Size().PosY() == 600);
	LT_TEST_EQUAL(baseCpuImage.Channels() == 4);
	LT_TEST_EQUAL(baseCpuImage.Pixels() == nullptr);

	Lt::Allocators::FixedLinear allocator(Lt::Allocators::FixedLinear::Mb * 4);

	Lt::u8* pixels = (Lt::u8*)allocator.Allocate(1024);

	baseCpuImage.Pixels(pixels);

	LT_TEST_EQUAL(baseCpuImage.Pixels() == pixels);
}

int main()
{
	TestGraphicsBaseCpuImageInit();

	return 0;
}