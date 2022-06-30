#include <Lt/Graphics/CpuImage.hpp>

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2u& size, const Lt::u8 channels, Lt::u8* pixels):
	_Size(size),
	_Channels(channels),
	_Pixels(pixels)
{
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuImage::Size()
{
	return _Size;
}
const Lt::u8* Lt::Graphics::CpuImage::Pixels()
{
	return _Pixels;
}
const Lt::u8 Lt::Graphics::CpuImage::Channels()
{
	return _Channels;
}