#include <Lt/Graphics/FpsLimiter.hpp>
#include <Lt/Core/Ticks.hpp>

Lt::Graphics::FpsLimiter::FpsLimiter(Lt::usize fps) :
	_Fps(fps), 
	_Ticks(0)
{
}

void Lt::Graphics::FpsLimiter::Mark()
{
	_Ticks = Lt::Core::Ticks();
}

void Lt::Graphics::FpsLimiter::Throttle() const
{
	if (1000 / _Fps > Lt::Core::Ticks() - _Ticks)
	{
		Lt::Core::Delay(1000 / _Fps - (Lt::Core::Ticks() - _Ticks));
	}
}