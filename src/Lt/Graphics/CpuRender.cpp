#include <Lt/Graphics/CpuRender.hpp>

Lt::Graphics::CpuRender::CpuRender(Lt::Graphics::CpuWindow* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(_BaseRender.Size())
{
}

void Lt::Graphics::CpuRender::Present()
{
	_Window->Present(_Canvas.Pixels());
}

Lt::Graphics::CpuImage* Lt::Graphics::CpuRender::Canvas()
{
	return &_Canvas;
}