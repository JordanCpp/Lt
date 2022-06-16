#include <Lt/Graphics/CpuRender.hpp>

Lt::Graphics::CpuRender::CpuRender(Lt::Graphics::CpuWindow* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(_BaseRender.Size())
{
}

const Lt::Graphics::Point2i& Lt::Graphics::CpuRender::Size()
{
	return _BaseRender.Size();
}

const Lt::Graphics::Color& Lt::Graphics::CpuRender::Color()
{
	return _BaseRender.Color();
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