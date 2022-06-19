#include <Lt/Graphics/CpuRender.hpp>

Lt::Graphics::CpuRender::CpuRender(Lt::Graphics::Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(_BaseRender.Size())
{
}

const Lt::Graphics::Point2u& Lt::Graphics::CpuRender::Size()
{
	return _BaseRender.Size();
}

const Lt::Graphics::Color& Lt::Graphics::CpuRender::Color()
{
	return _BaseRender.Color();
}

void Lt::Graphics::CpuRender::Clear()
{
	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

	for (Lt::usize i = 0; i < _Canvas.Size().PosX() * _Canvas.Size().PosY(); i++)
	{
		pixels[i] = Color();
	}
}

void Lt::Graphics::CpuRender::Color(const Lt::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void Lt::Graphics::CpuRender::Present()
{
	_Window->Present(_Canvas.Pixels());
}

Lt::Graphics::CpuImage* Lt::Graphics::CpuRender::Canvas()
{
	return &_Canvas;
}

void Lt::Graphics::CpuRender::Pixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (Size().PosX() * pos.PosY()) + pos.PosX();

	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();
	
	pixels[i] = Color();
}

const Lt::Graphics::Color& Lt::Graphics::CpuRender::GetPixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (Size().PosX() * pos.PosY()) + pos.PosX();

	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

	return	pixels[i];
}