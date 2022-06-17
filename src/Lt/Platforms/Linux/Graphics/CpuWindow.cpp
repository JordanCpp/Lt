#include <Lt/Platforms/Linux/Graphics/CpuWindow.hpp>

Lt::Graphics::Linux::CpuWindow::CpuWindow(Lt::Core::ErrorHandler& errorHandler, const Point2u& pos, const Point2u& size, const char* title) :
    _Window(errorHandler, pos, size, title)
{
}

Lt::Graphics::Linux::CpuWindow::~CpuWindow()
{
}

void Lt::Graphics::Linux::CpuWindow::Present(Lt::u8* pixels)
{
}

const Lt::Graphics::Point2u& Lt::Graphics::Linux::CpuWindow::Size()
{
    return _Window.Size();
}

const Lt::Graphics::Point2u& Lt::Graphics::Linux::CpuWindow::Pos()
{
    return _Window.Pos();
}

bool Lt::Graphics::Linux::CpuWindow::GetEvent(Lt::Events::Event& event)
{
    return _Window.GetEvent(event);
}

void Lt::Graphics::Linux::CpuWindow::StopEvent()
{
    _Window.StopEvent();
}

const char* Lt::Graphics::Linux::CpuWindow::Title()
{
    return _Window.Title();
}

void Lt::Graphics::Linux::CpuWindow::Title(const char* title)
{
    _Window.Title(title);
}