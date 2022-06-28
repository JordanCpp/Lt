#include <Lt/Graphics/CpuImageFromMemory.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Graphics::CpuImageFromMemory::CpuImageFromMemory(const Lt::u8 channels, const Lt::Graphics::Point2u& size, Lt::u8* pixels):
	_BaseCpuImage(channels, size, pixels)
{
	LT_ASSERT(pixels != nullptr);
}

Lt::Graphics::CpuImageFromMemory::~CpuImageFromMemory()
{
	Lt::u8* pixels = Pixels();

	pixels = nullptr;
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuImageFromMemory::Size()
{
	return _BaseCpuImage.Size();
}

Lt::u8* Lt::Graphics::CpuImageFromMemory::Pixels()
{
	return _BaseCpuImage.Pixels();
}

const Lt::u8 Lt::Graphics::CpuImageFromMemory::Channels()
{
	return _BaseCpuImage.Channels();
}
