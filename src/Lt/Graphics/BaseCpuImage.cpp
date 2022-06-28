#include <Lt/Graphics/BaseCpuImage.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Graphics::BaseCpuImage::BaseCpuImage(const Lt::u8 channels, const Lt::Graphics::Point2u& size, Lt::u8* pixels) :
	_Channels(channels),
	_Size(size),
	_Pixels(pixels)
{
	LT_ASSERT(channels > 0 && channels < 5);
	LT_ASSERT(size.PosX() > 0);
	LT_ASSERT(size.PosY() > 0);
}

const Lt::Graphics::Point2u& Lt::Graphics::BaseCpuImage::Size()
{
	return _Size;
}

Lt::u8* Lt::Graphics::BaseCpuImage::Pixels()
{
	return _Pixels;
}

void Lt::Graphics::BaseCpuImage::Pixels(Lt::u8* source)
{
	LT_ASSERT(source != nullptr);

	_Pixels = source;
}

const Lt::u8 Lt::Graphics::BaseCpuImage::Channels()
{
	return _Channels;
}