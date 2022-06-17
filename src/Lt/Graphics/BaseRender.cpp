#include <Lt/Graphics/BaseRender.hpp>

Lt::Graphics::BaseRender::BaseRender(const Lt::Graphics::Point2u& size) :
	_Size(size)
{
}

const Lt::Graphics::Point2u& Lt::Graphics::BaseRender::Size()
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