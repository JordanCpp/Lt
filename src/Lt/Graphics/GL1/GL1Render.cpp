#include <Lt/Graphics/GL1/GL1Render.hpp>
#include <gl/GL.h>

Lt::Graphics::GL1Render::GL1Render(Lt::Core::ErrorHandler* errorHandler, Lt::Graphics::GL1Window* window) :
	_ErrorHandler(errorHandler),
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
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

	GLint x1 = (GLint)pos1.PosX();
	GLint y1 = (GLint)pos1.PosY();
	GLint x2 = (GLint)pos2.PosX();
	GLint y2 = (GLint)pos2.PosY();

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void Lt::Graphics::GL1Render::Fill(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

	GLint x = (GLint)pos.PosX();
	GLint y = (GLint)pos.PosY();
	GLint w = (GLint)size.PosX();
	GLint h = (GLint)size.PosY();

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2i(x, y + h);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glEnd();
}

Lt::u8* Lt::Graphics::GL1Render::Pixels()
{
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, (GLsizei)_Canvas.Size().PosX(), (GLsizei)_Canvas.Size().PosY(), GL_RGBA, GL_UNSIGNED_BYTE, _Canvas.Pixels());

	return _Canvas.Pixels();
}

Lt::u8 Lt::Graphics::GL1Render::BytesPerPixel()
{
	return _Canvas.BytesPerPixel();
}

void Lt::Graphics::GL1Render::Draw(Lt::Graphics::GL1Image* image, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	glBindTexture(GL_TEXTURE_2D, (GLuint)image->Id());

	GLint x = (GLint)pos.PosX();
	GLint y = (GLint)pos.PosY();
	GLint w = (GLint)size.PosX();
	GLint h = (GLint)size.PosY();

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0);
	glVertex2i(x, y + h);
	glTexCoord2i(0, 1);
	glVertex2i(x, y);
	glTexCoord2i(1, 1);
	glVertex2i(x + w, y);
	glTexCoord2i(1, 0);
	glVertex2i(x + w, y + h);
	glEnd();
}

void Lt::Graphics::GL1Render::Draw(Lt::Graphics::GL1Image* image, const Lt::Graphics::Point2u& pos)
{
	Draw(image, pos, image->Size());
}