#include <Lt/Graphics/CpuRender.hpp>

Lt::Graphics::CpuRender::CpuRender(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(4, _BaseRender.Size())
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

	Lt::usize size = _Canvas.Size().PosX() * _Canvas.Size().PosY();

	for (Lt::usize i = 0; i < size; i++)
	{
		pixels[i] = _BaseRender._Current;
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

Lt::Graphics::ImageFromNew* Lt::Graphics::CpuRender::Canvas()
{
	return &_Canvas;
}

void Lt::Graphics::CpuRender::Pixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (Size().PosX() * pos.PosY()) + pos.PosX();

	if (i < Size().PosX() * Size().PosY())
	{
		Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

		pixels[i] = Color();
	}
}

const Lt::Graphics::Color& Lt::Graphics::CpuRender::GetPixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (Size().PosX() * pos.PosY()) + pos.PosX();

	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

	return	pixels[i];
}

void Lt::Graphics::CpuRender::FillRect(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	Lt::usize x = pos.PosX();
	Lt::usize y = pos.PosY();

	for (Lt::usize i = 0; i < size.PosX(); i++)
	{
		for (Lt::usize j = 0; j < size.PosY(); j++)
		{
			Pixel(Lt::Graphics::Point2u(x + i, y + j));
		}
	}
}

void Lt::Graphics::CpuRender::Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2)
{
	int x1 = pos1.PosX();
	int y1 = pos1.PosY();

	int x2 = pos2.PosX();
	int y2 = pos2.PosY();

	int deltaX;
	int deltaY;
	int signX;
	int signY;
	int error;
	int error2;

	deltaX = abs(x2 - x1);
	deltaY = abs(y2 - y1);
	signX = x1 < x2 ? 1 : -1;
	signY = y1 < y2 ? 1 : -1;

	error = deltaX - deltaY;

	Pixel(Lt::Graphics::Point2u(x2, y2));

	while (x1 != x2 || y1 != y2)
	{
		Pixel(Lt::Graphics::Point2u(x1, y1));

		error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}

		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

Lt::u8* Lt::Graphics::CpuRender::Pixels()
{
	return _Canvas.Pixels();
}

Lt::u8 Lt::Graphics::CpuRender::Channels()
{
	return _Canvas.Channels();
}