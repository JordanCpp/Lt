#include <Lt/Loaders/Image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"

Lt::Loaders::Image::Image(Lt::Core::ErrorHandler* errorHandler):
	_ErrorHandler(errorHandler),
	_Channels(0),
	_Pixels(nullptr)
{
}

Lt::Loaders::Image::~Image()
{
	Clear();
}

void Lt::Loaders::Image::Clear()
{
	if (_Pixels != nullptr)
		stbi_image_free(_Pixels);

	_ErrorHandler->Reset();
	_Pixels = nullptr;
}

const Lt::Graphics::Point2u& Lt::Loaders::Image::Size()
{
	return _Size;
}

Lt::u8 Lt::Loaders::Image::Channels()
{
	return _Channels;
}

Lt::u8* Lt::Loaders::Image::Pixels()
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