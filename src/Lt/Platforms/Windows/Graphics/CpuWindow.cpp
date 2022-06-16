#include <Lt/Platforms/Windows/Graphics/CpuWindow.hpp>

Lt::Graphics::CpuWindow::CpuWindow(Lt::Core::ErrorHandler& errorHandler, const Point2i& pos, const Point2i& size, const char* title) :
    _Window(errorHandler, pos, size, title)
{
}

Lt::Graphics::CpuWindow::~CpuWindow()
{
}

void Lt::Graphics::CpuWindow::Present(Lt::u8* pixels)
{
    ZeroMemory(&_BITMAPINFO, sizeof(_BITMAPINFO));

    _BITMAPINFO.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    _BITMAPINFO.bmiHeader.biWidth = (LONG)_Window.Size().PosX();
    _BITMAPINFO.bmiHeader.biHeight = -(LONG)_Window.Size().PosY();
    _BITMAPINFO.bmiHeader.biPlanes = 1;
    _BITMAPINFO.bmiHeader.biBitCount = 32;
    _BITMAPINFO.bmiHeader.biCompression = BI_RGB;

    SetDIBitsToDevice(_Window._HDC, 0, 0, _Window.Size().PosX(), _Window.Size().PosY(), 0, 0, 0, _Window.Size().PosY(), pixels, &_BITMAPINFO, DIB_RGB_COLORS);
}

const Lt::Graphics::Point2i& Lt::Graphics::CpuWindow::Size()
{
    return _Window.Size();
}

const Lt::Graphics::Point2i& Lt::Graphics::CpuWindow::Pos()
{
    return _Window.Pos();
}

bool Lt::Graphics::CpuWindow::GetEvent(Lt::Events::Event& event)
{
    return _Window.GetEvent(event);
}

void Lt::Graphics::CpuWindow::StopEvent()
{
    _Window.StopEvent();
}

const char* Lt::Graphics::CpuWindow::Title()
{
    return _Window.Title();
}

void Lt::Graphics::CpuWindow::Title(const char* title)
{
    _Window.Title(title);
}