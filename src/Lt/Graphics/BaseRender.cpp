#include <Lt/Graphics/BaseRender.hpp>

Lt::Graphics::BaseRender::BaseRender(const Lt::Graphics::Point2i& size) :
	_Size(size)
{
}

const Lt::Graphics::Point2i& Lt::Graphics::BaseRender::Size()
{
	return _Size;
}

const Lt::Graphics::Color& Lt::Graphics::BaseRender::Color()
{
	return _Current;
}

void Lt::Graphics::BaseRender::Color(const Lt::Graphics::Color& color)
{
	_Current = color;
}