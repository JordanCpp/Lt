#include <Lt/Loaders/ImageLoader.hpp>
#include <Lt/Core/Assert.hpp>

static Lt::Allocators::Allocator* StbImageAllocator;

#define STBI_MALLOC(sz)        StbImageAllocator->Allocate(sz);
#define STBI_REALLOC(p,newsz)  StbImageAllocator->Reallocate(p,newsz)
#define STBI_FREE(p)           StbImageAllocator->Deallocate(p) 

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"

Lt::Loaders::ImageLoader::ImageLoader(Lt::Core::ErrorHandler* errorHandler, Lt::Allocators::Allocator* allocator):
	_ErrorHandler(errorHandler),
	_Allocator(allocator),
	_Channels(0),
	_Pixels(nullptr)
{
	LT_ASSERT(errorHandler != nullptr);
	LT_ASSERT(allocator != nullptr);

	StbImageAllocator = _Allocator;
}

Lt::Loaders::ImageLoader::~ImageLoader()
{
	Clear();
}

void Lt::Loaders::ImageLoader::Clear()
{
	_Allocator->Reset();
	_ErrorHandler->Reset();
	_Pixels = nullptr;
}

const Lt::Graphics::Point2u& Lt::Loaders::ImageLoader::Size()
{
	return _Size;
}

const Lt::u8 Lt::Loaders::ImageLoader::Channels()
{
	return _Channels;
}

const Lt::u8* Lt::Loaders::ImageLoader::Pixels()
{
	return _Pixels;
}

void Lt::Loaders::ImageLoader::Load(const char* path)
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