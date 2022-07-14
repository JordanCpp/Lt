#include "Engine.hpp"
#include <Lt/Core/Memory.hpp>

Engine::Engine(const Lt::Graphics::Point2u size):
	_Window(&_ErrorHandler, Lt::Graphics::Point2u(0, 0), size, "Game"),
	_Render(&_ErrorHandler, &_Window)
{
}

void Engine::Run()
{
	Lt::Events::Event event;

	Lt::Memory::Zero(&event, sizeof(Lt::Events::Event));

	while (_Window.GetEvent(event))
	{
		if (event.Type == Lt::Events::IsQuit)
			_Window.StopEvent();

		_Render.Present();

		CalcFps();
	}
}

void Engine::CalcFps()
{
	if (_FpsCounter.Calc())
	{
		if (_IntegerToString.Convert(_FpsCounter.Fps()))
		{
			_Window.Title(_IntegerToString.Result());
		}

		_FpsCounter.Clear();
	}
}