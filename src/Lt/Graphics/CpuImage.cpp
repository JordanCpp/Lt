#include <Lt/Graphics/CpuImage.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Graphics::CpuImage::CpuImage() :
	_Channels(4),
	_Allocator(nullptr),
	_Pixels(nullptr)
{
}

void Lt::Graphics::CpuImage::FromNew(const Lt::Graphics::Point2u& size)
{
	LT_ASSERT(size.PosX() > 0);
	LT_ASSERT(size.PosY() > 0);

	_Size = size;
	_Allocator = nullptr;
	_Pixels = nullptr;

	Lt::usize bytes = Size().PosX() * Size().PosX() * Channels();

	_Pixels = new Lt::u8[bytes];
}
void Lt::Graphics::CpuImage::FromMemory(const Lt::Graphics::Point2u& size, Lt::u8* pixels)
{
	LT_ASSERT(size.PosX() > 0);
	LT_ASSERT(size.PosY() > 0);
	LT_ASSERT(pixels != nullptr);

	_Size = size;
	_Allocator = nullptr;
	_Pixels = pixels;
}
void Lt::Graphics::CpuImage::FromAllocator(const Lt::Graphics::Point2u& size, Lt::Allocators::Allocator* allocator)
{
	LT_ASSERT(size.PosX() > 0);
	LT_ASSERT(size.PosY() > 0);
	LT_ASSERT(_Allocator != allocator);

	_Size = size;
	_Allocator = allocator;
	_Pixels = nullptr;

	Lt::usize bytes = Size().PosX() * Size().PosX() * Channels();

	_Pixels = (Lt::u8*)_Allocator->Allocate(bytes);
}

Lt::Graphics::CpuImage::~CpuImage()
{
	if (_Allocator != nullptr)
		_Allocator->Deallocate(_Pixels);
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuImage::Size()
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