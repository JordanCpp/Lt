#include <Lt/Graphics/GL1Render.hpp>
#include <gl/GL.h>

Lt::Graphics::GL1Render::GL1Render(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::Window* window) :
	_Window(window),
	_BaseRender(_Window->Size())
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, (GLdouble)_Window->Size().PosX(), (GLdouble)_Window->Size().PosY(), 0.0f, 0.0f, 1.0f);
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

void Lt::Graphics::GL1Render::Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2)
{
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex2i((GLint)pos1.PosX(), (GLint)pos1.PosY());
	glVertex2i((GLint)pos2.PosX(), (GLint)pos2.PosY());
	glEnd();
}

void Lt::Graphics::GL1Render::FillRect(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	glBegin(GL_QUADS);
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY() + (GLint)size.PosY());
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY());
	glVertex2i((GLint)pos.PosX() + (GLint)size.PosX(), (GLint)pos.PosY());
	glVertex2i((GLint)pos.PosX() + (GLint)size.PosX(), (GLint)pos.PosY() + (GLint)size.PosY());
	glEnd();
}