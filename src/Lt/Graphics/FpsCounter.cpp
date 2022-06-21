#include <Lt/Graphics/FpsCounter.hpp>

Lt::Graphics::FpsCounter::FpsCounter(Lt::usize milliseconds):
	_Milliseconds(milliseconds),
	_Fps(0),
	_OldTime(Ticks())
{
}

Lt::usize Lt::Graphics::FpsCounter::Ticks()
{
	return Lt::Core::Ticks() % 1000;
}

bool Lt::Graphics::FpsCounter::Calc()
{
	_Fps++;

	if ((Ticks() - _OldTime) >= _Milliseconds)
	{
		_OldTime = Ticks();

		return true;
	}

	_OldTime = Ticks();

	return false;
}

void Lt::Graphics::FpsCounter::Clear()
{
	_Fps = 0;
}

Lt::usize Lt::Graphics::FpsCounter::Fps()
{
	return _Fps;
}