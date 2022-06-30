#include <Lt/Loaders/Image.hpp>

static Lt::Allocators::Allocator* StbImageAllocator;

#define STBI_MALLOC(sz)        StbImageAllocator->Allocate(sz);
#define STBI_REALLOC(p,newsz)  StbImageAllocator->Reallocate(p,newsz)
#define STBI_FREE(p)           StbImageAllocator->Deallocate(p) 

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"

Lt::Loaders::Image::Image(Lt::Core::ErrorHandler* errorHandler, Lt::Allocators::Allocator* allocator):
	_ErrorHandler(errorHandler),
	_Allocator(allocator),
	_Channels(0),
	_Pixels(nullptr)
{
	StbImageAllocator = _Allocator;
}

Lt::Loaders::Image::~Image()
{
	Clear();
}

void Lt::Loaders::Image::Clear()
{
	_Allocator->Reset();
	_ErrorHandler->Reset();
	_Pixels = nullptr;
}

const Lt::Graphics::Point2u& Lt::Loaders::Image::Size()
{
	return _Size;
}

const Lt::u8 Lt::Loaders::Image::Channels()
{
	return _Channels;
}

const Lt::u8* Lt::Loaders::Image::Pixels()
{
	return _Pixels;
}

void Lt::Loaders::Image::Load(const char* path)
{
	Clear();

	int width = 0;
	int height = 0;
	int channels = 0;

	_Pixels = stbi_load(path, &width, &height, &channels, 0);

	_Size = Lt::Graphics::Point2u(width, height);
	_Channels = channels;

	if (_Pixels == nullptr)
		_ErrorHandler->Message("stbi_load");
}