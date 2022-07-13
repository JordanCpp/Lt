#include <Lt/Graphics/Cpu/CpuRender.hpp>

Lt::Graphics::CpuRender::CpuRender(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::CpuWindow* window) :
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

Lt::Graphics::CpuImage* Lt::Graphics::CpuRender::Canvas()
{
	return &_Canvas;
}

void Lt::Graphics::CpuRender::Pixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (_BaseRender._Size._PosX * pos._PosY) + pos._PosX;

	if (i < _BaseRender._Size._PosX * _BaseRender._Size._PosY)
	{
		Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

		pixels[i] = _BaseRender._Current;
	}
}

const Lt::Graphics::Color& Lt::Graphics::CpuRender::GetPixel(const Lt::Graphics::Point2u& pos)
{
	Lt::usize i = (Size().PosX() * pos.PosY()) + pos.PosX();

	Lt::Graphics::Color* pixels = (Lt::Graphics::Color*)_Canvas.Pixels();

	return	pixels[i];
}

void Lt::Graphics::CpuRender::Fill(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
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

void Lt::Graphics::CpuRender::Rect(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size)
{
	Lt::usize x = pos.PosX();
	Lt::usize y = pos.PosY();
	Lt::usize w = size.PosX();
	Lt::usize h = size.PosY();

	for (Lt::usize i = 0; i < w; i++)
	{
		Pixel(Lt::Graphics::Point2u(x + i, y));
	}

	for (Lt::usize i = 0; i < w; i++)
	{
		Pixel(Lt::Graphics::Point2u(x + i, y + h));
	}

	for (Lt::usize i = 0; i < h; i++)
	{
		Pixel(Lt::Graphics::Point2u(x, y + i));
	}

	for (Lt::usize i = 0; i < h; i++)
	{
		Pixel(Lt::Graphics::Point2u(x + w, y + i));
	}
}

void Lt::Graphics::CpuRender::Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2)
{
	int x1 = (int)pos1.PosX();
	int y1 = (int)pos1.PosY();

	int x2 = (int)pos2.PosX();
	int y2 = (int)pos2.PosY();

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

Lt::u8 Lt::Graphics::CpuRender::BytesPerPixel()
{
	return _Canvas.BytesPerPixel();
}