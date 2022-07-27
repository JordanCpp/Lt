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
	_BytesPerPixel(0),
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
	_Size = Lt::Graphics::Point2u(0, 0);
	_BytesPerPixel = 0;
}

const Lt::Graphics::Point2u& Lt::Loaders::ImageLoader::Size()
{
	return _Size;
}

const Lt::u8 Lt::Loaders::ImageLoader::BytesPerPixel()
{
	return _BytesPerPixel;
}

const Lt::u8* Lt::Loaders::ImageLoader::Pixels()
{
	return _Pixels;
}

void Lt::Loaders::ImageLoader::Load(const char* path)
{
	LT_ASSERT(path != nullptr);

	Clear();

	int width = 0;
	int height = 0;
	int bytesPerPixel = 0;

	stbi_set_flip_vertically_on_load(true);

	_Pixels = stbi_load(path, &width, &height, &bytesPerPixel, 0);

	_Size = Lt::Graphics::Point2u(width, height);
	_BytesPerPixel = bytesPerPixel;

	if (_Pixels == nullptr)
		_ErrorHandler->Message("stbi_load");
}