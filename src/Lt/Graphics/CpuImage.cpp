#include <Lt/Graphics/CpuImage.hpp>

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2i& size) :
	_Size(size),
	_Channels(4),
	_Allocator(nullptr),
	_Pixels(nullptr)
{
	Lt::usize bytes = Size().PosX() * Size().PosX() * Channels();

	_Pixels = new Lt::u8[bytes];
}

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2i& size, Lt::u8* pixels) :
	_Size(size),
	_Channels(4),
	_Allocator(nullptr),
	_Pixels(pixels)
{
}

Lt::Graphics::CpuImage::CpuImage(const Lt::Graphics::Point2i& size, Lt::Allocators::Allocator* allocator):
	_Size(size),
	_Channels(4),
	_Allocator(allocator),
	_Pixels(nullptr)
{
	Lt::usize bytes = Size().PosX() * Size().PosX() * Channels();

	_Pixels = (Lt::u8*)_Allocator->Allocate(bytes);
}

Lt::Graphics::CpuImage::~CpuImage()
{
	if (_Allocator != nullptr)
		_Allocator->Deallocate(_Pixels);
}

const Lt::Graphics::Point2i& Lt::Graphics::CpuImage::Size()
{
	return _Size;
}

const Lt::u8 Lt::Graphics::CpuImage::Channels()
{
	return _Channels;
}

Lt::u8* Lt::Graphics::CpuImage::Pixels()
{
	return _Pixels;
}

const Lt::Allocators::Allocator* Lt::Graphics::CpuImage::Allocator()
{
	return _Allocator;
}