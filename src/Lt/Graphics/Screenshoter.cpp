#include <Lt/Graphics/Screenshoter.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

Lt::Graphics::Screenshoter::Screenshoter(Lt::Graphics::Render* render, const char* path) :
	_Render(render),
	_ShortPath(path)
{
}

void Lt::Graphics::Screenshoter::Shot(const char* path)
{
	_FullPath.Clear();

	_FullPath.Append(_ShortPath.Content());
	_FullPath.Append(path);

	stbi_write_png(_FullPath.Content(), (int)_Render->Size().PosX(), (int)_Render->Size().PosY(), 4, _Render->Pixels(), (int)_Render->Size().PosX() * (int)_Render->Channels());
}