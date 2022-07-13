#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/Cpu/CpuImage.hpp>

void TestGraphicsCpuImageInitNew()
{
	Lt::Graphics::CpuImage image(Lt::Graphics::Point2u(800, 600));

	LT_TEST_EQUAL(image.Size().PosX() == 800);
	LT_TEST_EQUAL(image.Size().PosY() == 600);
	LT_TEST_EQUAL(image.BytesPerPixel() == 4);
	LT_TEST_EQUAL(image.Pixels() != nullptr);
}

void TestGraphicsCpuImageInitPixels()
{
	Lt::Graphics::Point2u size(800, 600);

	Lt::u8* bytes = new Lt::u8[size.PosX() * size.PosY() * 4];

	Lt::Graphics::CpuImage image(size, bytes);

	LT_TEST_EQUAL(image.Size().PosX() == 800);
	LT_TEST_EQUAL(image.Size().PosY() == 600);
	LT_TEST_EQUAL(image.BytesPerPixel() == 4);
	LT_TEST_EQUAL(image.Pixels() != nullptr);
	LT_TEST_EQUAL(image.Pixels() == bytes);

	delete[] bytes;
}

int main()
{
	TestGraphicsCpuImageInitNew();
	TestGraphicsCpuImageInitPixels();

	return 0;
}