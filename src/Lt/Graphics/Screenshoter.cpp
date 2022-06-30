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
	stbi_write_png(path, (int)_Render->Size().PosX(), (int)_Render->Size().PosY(), 4, _Render->Pixels(), (int)_Render->Size().PosX() * (int)_Render->Channels());
}

void Lt::Graphics::Screenshoter::Shot()
{
	_Current.Now();

	_FullPath.Clear();

	_FullPath.Append(_ShortPath.Content());
	_FullPath.Append("Screenshot-");

	_Conv.Convert(_Current.Days());
	_FullPath.Append(_Conv.Result());
	_FullPath.Append(".");

	_Conv.Convert(_Current.Months());
	_FullPath.Append(_Conv.Result());
	_FullPath.Append(".");

	_Conv.Convert(_Current.Years());
	_FullPath.Append(_Conv.Result());

	_FullPath.Append("-");

	_Conv.Convert(_Current.Hours());
	_FullPath.Append(_Conv.Result());
	_FullPath.Append(".");

	_Conv.Convert(_Current.Minutes());
	_FullPath.Append(_Conv.Result());
	_FullPath.Append(".");

	_Conv.Convert(_Current.Seconds());
	_FullPath.Append(_Conv.Result());

	_FullPath.Append(".png");

	Shot(_FullPath.Content());
}

const char* Lt::Graphics::Screenshoter::Path()
{
	return _FullPath.Content();
}