#include <Lt/Platforms/Windows/Graphics/Monitor.hpp>
#include <Windows.h>

Lt::Graphics::Windows::Monitor::Monitor()
{
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::Monitor::Resolution()
{
	HDC hdc = GetDC(NULL);

	int w = GetDeviceCaps(hdc, HORZRES);
	int h = GetDeviceCaps(hdc, VERTRES);

	_Current = Lt::Graphics::Point2u(w, h);

	ReleaseDC(nullptr, hdc);

	return _Current;
}