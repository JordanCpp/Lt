#include <Lt/Core/TestEqual.hpp>
#include <Lt/Graphics/PixelConverter.hpp>

void TestGraphicsPixelConverterFill()
{
	Lt::Graphics::Point2u size(800, 600);
	Lt::u8 channels = 4;

	Lt::Graphics::Color* pixels = new Lt::Graphics::Color[size.PosX() * size.PosY()];

	Lt::Graphics::PixelConverter pixelConverter;

	pixelConverter.Fill((Lt::u8*)pixels, size, channels, Lt::Graphics::Color(1, 2, 3, 4));

	for (Lt::usize i = 0; i < size.PosX() * size.PosY(); i++)
	{
		LT_TEST_EQUAL(pixels[i].Red() == 1);
		LT_TEST_EQUAL(pixels[i].Green() == 2);
		LT_TEST_EQUAL(pixels[i].Blue() == 3);
		LT_TEST_EQUAL(pixels[i].Alpha() == 4);
	}

	delete[] pixels;
}

void TestGraphicsPixelConverterBgrToRgb()
{
	Lt::Graphics::Point2u size(800, 600);
	Lt::u8 channels = 4;

	Lt::Graphics::Color* pixels = new Lt::Graphics::Color[size.PosX() * size.PosY()];

	Lt::Graphics::PixelConverter pixelConverter;

	pixelConverter.Fill((Lt::u8*)pixels, size, channels, Lt::Graphics::Color(1, 2, 3, 4));

	pixelConverter.BgrToRgb((Lt::u8*)pixels, size, channels);

	for (Lt::usize i = 0; i < size.PosX() * size.PosY(); i++)
	{
		LT_TEST_EQUAL(pixels[i].Red() == 3);
		LT_TEST_EQUAL(pixels[i].Green() == 2);
		LT_TEST_EQUAL(pixels[i].Blue() == 1);
		LT_TEST_EQUAL(pixels[i].Alpha() == 4);
	}

	delete[] pixels;
}

void TestGraphicsPixelConverterRgbToBgr()
{
	Lt::Graphics::Point2u size(800, 600);
	Lt::u8 channels = 4;

	Lt::Graphics::Color* pixels = new Lt::Graphics::Color[size.PosX() * size.PosY()];

	Lt::Graphics::PixelConverter pixelConverter;

	pixelConverter.Fill((Lt::u8*)pixels, size, channels, Lt::Graphics::Color(1, 2, 3, 4));

	pixelConverter.BgrToRgb((Lt::u8*)pixels, size, channels);

	for (Lt::usize i = 0; i < size.PosX() * size.PosY(); i++)
	{
		LT_TEST_EQUAL(pixels[i].Red() == 3);
		LT_TEST_EQUAL(pixels[i].Green() == 2);
		LT_TEST_EQUAL(pixels[i].Blue() == 1);
		LT_TEST_EQUAL(pixels[i].Alpha() == 4);
	}

	delete[] pixels;
}

int main()
{
	TestGraphicsPixelConverterFill();
	TestGraphicsPixelConverterBgrToRgb();
	TestGraphicsPixelConverterRgbToBgr();

	return 0;
}