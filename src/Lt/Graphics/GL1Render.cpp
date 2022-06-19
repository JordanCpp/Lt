#include <Lt/Graphics/GL1Render.hpp>
#include <gl/GL.h>

Lt::Graphics::GL1Render::GL1Render(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::Window* window) :
	_Window(window),
	_BaseRender(_Window->Size())
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, _Window->Size().PosX(), _Window->Size().PosY(), 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
}

const Lt::Graphics::Point2u& Lt::Graphics::GL1Render::Size()
{
	return _BaseRender.Size();
}

const Lt::Graphics::Color& Lt::Graphics::GL1Render::Color()
{
	return _BaseRender.Color();
}

void Lt::Graphics::GL1Render::Clear()
{
	glClearColor(_BaseRender.Color().Red(), _BaseRender.Color().Green(), _BaseRender.Color().Blue(), _BaseRender.Color().Alpha());
	glClear(GL_COLOR_BUFFER_BIT);
}

void Lt::Graphics::GL1Render::Color(const Lt::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void Lt::Graphics::GL1Render::Present()
{
	_Window->Present();
}