#include "Engine.hpp"
#include <Lt/Core/Memory.hpp>

Engine::Engine(const Lt::Graphics::Point2u size) :
	_PathManager(""),
	_GeneralAllocator(Lt::Allocators::Allocator::Mb * 16),
	_ImageLoaderAllocator(Lt::Allocators::Allocator::Mb * 2, &_GeneralAllocator),
	_ImageCache(Lt::Allocators::Allocator::Mb * 8, &_GeneralAllocator),
	_ImageLoader(&_ErrorHandler, &_ImageLoaderAllocator),
	_Window(&_ErrorHandler, Lt::Graphics::Point2u(0, 0), size, "Game"),
	_Render(&_ErrorHandler, &_Window),
	_ImageFactory(&_ImageCache, &_ImageLoader)
{
}

void Engine::Run()
{
	Lt::Events::Event event;

	Lt::Memory::Zero(&event, sizeof(Lt::Events::Event));

	while (_Window.GetEvent(event))
	{
		_Render.Clear();

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