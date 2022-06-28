#include <Lt/Graphics/CpuImageFromNew.hpp>

Lt::Graphics::CpuImageFromNew::CpuImageFromNew(const Lt::u8 channels, const Lt::Graphics::Point2u& size) :
	_BaseCpuImage(channels, size, nullptr)
{
	Lt::usize bytes = Size().PosX() * Size().PosY() * Channels();

	Lt::u8* pixels = new Lt::u8[bytes];

	_BaseCpuImage.Pixels(pixels);
}

Lt::Graphics::CpuImageFromNew::~CpuImageFromNew()
{
	delete[] Pixels();
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuImageFromNew::Size()
{
	return _BaseCpuImage.Size();
}

Lt::u8* Lt::Graphics::CpuImageFromNew::Pixels()
{
	return _BaseCpuImage.Pixels();
}

const Lt::u8 Lt::Graphics::CpuImageFromNew::Channels()
{
	return _BaseCpuImage.Channels();
}
