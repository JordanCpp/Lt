#include <Lt/Graphics/Cpu/CpuImage.hpp>

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2u& size, const Lt::u8 channels):
	_Source(FromNew),
	_Size(size),
	_Channels(channels),
	_Pixels(nullptr)
{
	Lt::usize bytes = Size().PosX() * Size().PosY() * Channels();

	_Pixels = new Lt::u8[bytes];
}

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2u& size, const Lt::u8 channels, Lt::u8* pixels):
	_Source(FromMemory),
	_Size(size),
	_Channels(channels),
	_Pixels(pixels)
{
}

Lt::Graphics::CpuImage::~CpuImage()
{
	if (_Source == FromNew)
		delete[] _Pixels;
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuImage::Size()
{
	return _Size;
}

Lt::u8* Lt::Graphics::CpuImage::Pixels()
{
	return _Pixels;
}
const Lt::u8 Lt::Graphics::CpuImage::Channels()
{
	return _Channels;
}