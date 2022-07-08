#include <Lt/Platforms/Windows/Graphics/CpuWindow.hpp>

Lt::Graphics::Windows::CpuWindow::CpuWindow(Lt::Core::ErrorHandler* errorHandler, const Point2u& pos, const Point2u& size, const char* title) :
    _Window(errorHandler, pos, size, title)
{
}

Lt::Graphics::Windows::CpuWindow::~CpuWindow()
{
}

void Lt::Graphics::Windows::CpuWindow::Present(Lt::u8* pixels)
{
    ZeroMemory(&_BITMAPINFO, sizeof(_BITMAPINFO));

    _BITMAPINFO.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    _BITMAPINFO.bmiHeader.biWidth = (LONG)_Window.Size().PosX();
    _BITMAPINFO.bmiHeader.biHeight = -(LONG)_Window.Size().PosY();
    _BITMAPINFO.bmiHeader.biPlanes = 1;
    _BITMAPINFO.bmiHeader.biBitCount = 32;
    _BITMAPINFO.bmiHeader.biCompression = BI_RGB;

    SetDIBitsToDevice(_Window._HDC, 0, 0, (DWORD)_Window.Size().PosX(), (DWORD)_Window.Size().PosY(), 0, 0, 0, (UINT)_Window.Size().PosY(), pixels, &_BITMAPINFO, DIB_RGB_COLORS);
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::CpuWindow::Size()
{
    return _Window.Size();
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::CpuWindow::Pos()
{
    return _Window.Pos();
}

bool Lt::Graphics::Windows::CpuWindow::GetEvent(Lt::Events::Event& event)
{
    return _Window.GetEvent(event);
}

void Lt::Graphics::Windows::CpuWindow::StopEvent()
{
    _Window.StopEvent();
}

const char* Lt::Graphics::Windows::CpuWindow::Title()
{
    return _Window.Title();
}

void Lt::Graphics::Windows::CpuWindow::Title(const char* title)
{
    _Window.Title(title);
}