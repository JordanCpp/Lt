#include <Lt/Platforms/Linux/Graphics/Window.hpp>
#include <Lt/Core/Memory.hpp>

Lt::Graphics::Linux::Window::Window(Lt::Core::ErrorHandler& errorHandler, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size, const char* title) :
    _BaseWindow(pos, size, title)
{
}

Lt::Graphics::Linux::Window::~Window()
{
}

bool Lt::Graphics::Linux::Window::GetEvent(Lt::Events::Event& event)
{
    return _Eventer.Running();
}

void Lt::Graphics::Linux::Window::StopEvent()
{
    _Eventer.Stop();
}

void Lt::Graphics::Linux::Window::Title(const char* title)
{
    _BaseWindow.Title(title);
}

const char* Lt::Graphics::Linux::Window::Title()
{
    return _BaseWindow.Title();
}

const Lt::Graphics::Point2u& Lt::Graphics::Linux::Window::Size()
{
    return _BaseWindow.Size();
}

const Lt::Graphics::Point2u& Lt::Graphics::Linux::Window::Pos()
{
    return _BaseWindow.Pos();
}