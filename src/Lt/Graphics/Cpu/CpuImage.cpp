#include <Lt/Graphics/Cpu/CpuImage.hpp>

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel):
	_Source(FromNew),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(nullptr)
{
	Lt::usize bytes = Size().PosX() * Size().PosY() * BytesPerPixel();

	_Pixels = new Lt::u8[bytes];
}

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2u& size, Lt::u8* pixels, const Lt::u8 bytesPerPixel):
	_Source(FromMemory),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
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
const Lt::u8 Lt::Graphics::CpuImage::BytesPerPixel()
{
	return _BytesPerPixel;
}