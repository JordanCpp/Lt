#include <Lt/Graphics/BaseWindow.hpp>

Lt::Graphics::BaseWindow::BaseWindow(const Lt::Graphics::Point2i& pos, const Lt::Graphics::Point2i& size, const char* title):
    _Pos(pos),
    _Size(size),
    _Title(title)
{
}

const Lt::Graphics::Point2i& Lt::Graphics::BaseWindow::Pos()
{
    return _Pos;
}

const Lt::Graphics::Point2i& Lt::Graphics::BaseWindow::Size()
{
    return _Size;
}

const char* Lt::Graphics::BaseWindow::Title()
{
    return _Title.Content();
}

void Lt::Graphics::BaseWindow::Title(const char* source)
{
    _Title.Assign(source);
}