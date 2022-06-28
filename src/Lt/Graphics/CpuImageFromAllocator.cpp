#include <Lt/Graphics/CpuImageFromAllocator.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Graphics::CpuImageFromAllocator::CpuImageFromAllocator(const Lt::u8 channels, const Lt::Graphics::Point2u& size, Lt::Allocators::Allocator* allocator) :
	_BaseCpuImage(channels, size, nullptr),
	_Allocator(allocator)
{
	LT_ASSERT(_Allocator != nullptr);

	Lt::usize bytes = Size().PosX() * Size().PosY() * Channels();

	Lt::u8* pixels = (Lt::u8*)_Allocator->Allocate(bytes);

	_BaseCpuImage.Pixels(pixels);
}

Lt::Graphics::CpuImageFromAllocator::~CpuImageFromAllocator()
{
	_Allocator->Deallocate(Pixels());
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuImageFromAllocator::Size()
{
	return _BaseCpuImage.Size();
}

Lt::u8* Lt::Graphics::CpuImageFromAllocator::Pixels()
{
	return _BaseCpuImage.Pixels();
}

const Lt::u8 Lt::Graphics::CpuImageFromAllocator::Channels()
{
	return _BaseCpuImage.Channels();
}

const Lt::Allocators::Allocator* Lt::Graphics::CpuImageFromAllocator::Allocator()
{
	return _Allocator;
}