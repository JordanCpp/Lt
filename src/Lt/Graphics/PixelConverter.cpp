#include <Lt/Graphics/PixelConverter.hpp>

void Lt::Graphics::PixelConverter::Fill(Lt::u8* pixels, const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel, const Lt::Graphics::Color& color)
{
	Lt::usize bytes = size.PosX() * size.PosY() * bytesPerPixel;

#if defined(LT_CONFIG_OS_WINDOWS)
	for (Lt::usize i = 0; i < bytes; i += bytesPerPixel)
	{
		pixels[i + 0] = color.Blue();
		pixels[i + 1] = color.Green();
		pixels[i + 2] = color.Red();
		pixels[i + 3] = color.Alpha();
	}
#else
	Lt::usize bytes = size.PosX() * size.PosY() * BytesPerPixel;

	for (Lt::usize i = 0; i < bytes; i += BytesPerPixel)
	{
		pixels[i + 0] = color.Red();
		pixels[i + 1] = color.Green();
		pixels[i + 2] = color.Blue();
		pixels[i + 3] = color.Alpha();
	}
#endif
}

void Lt::Graphics::PixelConverter::RgbToBgr(Lt::u8* pixels, const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel)
{
	Lt::usize bytes = size.PosX() * size.PosY() * bytesPerPixel;

	for (Lt::usize i = 0; i < bytes; i += 4)
	{
		Lt::u8 temp = pixels[i + 2];
		pixels[i + 2] = pixels[i + 0];
		pixels[i + 0] = temp;
	}
}

void Lt::Graphics::PixelConverter::BgrToRgb(Lt::u8* pixels, const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel)
{
	Lt::usize bytes = size.PosX() * size.PosY() * bytesPerPixel;

	for (Lt::usize i = 0; i < bytes; i += 4)
	{
		Lt::u8 temp = pixels[i + 0];
		pixels[i + 0] = pixels[i + 2];
		pixels[i + 2] = temp;
	}
}