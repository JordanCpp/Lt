#include <Lt/Graphics/BaseRender.hpp>

const Lt::Graphics::Color& Lt::Graphics::BaseRender::Color()
{
	return _Current;
}

void Lt::Graphics::BaseRender::Color(const Lt::Graphics::Color& color)
{
	_Current = color;
}