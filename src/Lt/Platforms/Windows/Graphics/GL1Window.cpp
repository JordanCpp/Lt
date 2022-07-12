#include <Lt/Platforms/Windows/Graphics/GL1Window.hpp>

Lt::Graphics::Windows::GL1Window::GL1Window(Lt::Core::ErrorHandler* errorHandler, const Point2u& pos, const Point2u& size, const char* title) :
    _Window(errorHandler, pos, size, title)
{
    PIXELFORMATDESCRIPTOR pfd = { 0 };

    int format = 0;

    _Window._HDC = GetDC(_Window._HWND);

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    format = ChoosePixelFormat(_Window._HDC, &pfd);

    if (format == 0)
    {
        errorHandler->Message("ChoosePixelFormat");
    }
    else
    {
        SetPixelFormat(_Window._HDC, format, &pfd);

        _HGLRC = wglCreateContext(_Window._HDC);

        wglMakeCurrent(_Window._HDC, _HGLRC);
    }
}

Lt::Graphics::Windows::GL1Window::~GL1Window()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);
    ReleaseDC(_Window._HWND, _Window._HDC);
}

void Lt::Graphics::Windows::GL1Window::Present()
{
    SwapBuffers(_Window._HDC);
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::GL1Window::Size()
{
    return _Window.Size();
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::GL1Window::Pos()
{
    return _Window.Pos();
}

bool Lt::Graphics::Windows::GL1Window::GetEvent(Lt::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool Lt::Graphics::Windows::GL1Window::WaitEvent(Lt::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void Lt::Graphics::Windows::GL1Window::StopEvent()
{
    _Window.StopEvent();
}

const char* Lt::Graphics::Windows::GL1Window::Title()
{
    return _Window.Title();
}

void Lt::Graphics::Windows::GL1Window::Title(const char* title)
{
    _Window.Title(title);
}