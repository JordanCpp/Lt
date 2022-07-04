#include <Lt/Graphics/GL1/GL1Render.hpp>
#include <gl/GL.h>

Lt::Graphics::GL1Render::GL1Render(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::GL1Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(_BaseRender.Size())
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
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;
	GLclampf a = _BaseRender.Color().Alpha() / 255.0f;

	glClearColor(r, g, b, 1.0f);
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

Lt::Graphics::CpuImage* Lt::Graphics::GL1Render::Canvas()
{
	return &_Canvas;
}

void Lt::Graphics::GL1Render::Pixel(const Lt::Graphics::Point2u& pos)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

	glColor3f(r, g, b);

	glBegin(GL_POINTS);
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY());
	glEnd();
}

const Lt::Graphics::Color& Lt::Graphics::GL1Render::GetPixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (Size().PosX() * pos.PosY()) + pos.PosX();

	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

	return	pixels[i];
}

void Lt::Graphics::GL1Render::Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

	glColor3f(r, g, b);

	glBegin(GL_LINES);
	glVertex2i((GLint)pos1.PosX(), (GLint)pos1.PosY());
	glVertex2i((GLint)pos2.PosX(), (GLint)pos2.PosY());
	glEnd();
}

void Lt::Graphics::GL1Render::Fill(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

	glColor3f(r, g, b);

	glBegin(GL_QUADS);
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY() + (GLint)size.PosY());
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY());
	glVertex2i((GLint)pos.PosX() + (GLint)size.PosX(), (GLint)pos.PosY());
	glVertex2i((GLint)pos.PosX() + (GLint)size.PosX(), (GLint)pos.PosY() + (GLint)size.PosY());
	glEnd();
}

Lt::u8* Lt::Graphics::GL1Render::Pixels()
{
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, (GLsizei)_Canvas.Size().PosX(), (GLsizei)_Canvas.Size().PosY(), GL_RGBA, GL_UNSIGNED_BYTE, _Canvas.Pixels());

	return _Canvas.Pixels();
}

Lt::u8 Lt::Graphics::GL1Render::Channels()
{
	return _Canvas.Channels();
}