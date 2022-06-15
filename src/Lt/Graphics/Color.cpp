#include <Lt/Graphics/Color.hpp>

Lt::Graphics::Color::Color() :
	_Red(0),
	_Green(0),
	_Blue(0),
	_Alpha(255)
{
}

Lt::Graphics::Color::Color(Lt::u8 red, Lt::u8 green, Lt::u8 blue, Lt::u8 alpha) :
	_Red(red),
	_Green(green),
	_Blue(blue),
	_Alpha(alpha)
{
}

Lt::u8 Lt::Graphics::Color::Red() const
{
	return _Red;
}

Lt::u8 Lt::Graphics::Color::Green() const
{
	return _Green;
}

Lt::u8 Lt::Graphics::Color::Blue() const
{
	return _Blue;
}

Lt::u8 Lt::Graphics::Color::Alpha() const
{
	return _Alpha;
}