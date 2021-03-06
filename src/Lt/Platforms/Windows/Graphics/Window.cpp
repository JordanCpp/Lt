#include <Lt/Platforms/Windows/Graphics/Window.hpp>
#include <Lt/Core/Memory.hpp>

const char AppName[] = "Lt::Graphics::Window";

LRESULT CALLBACK Lt::Graphics::Windows::Window::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
{
    Lt::Events::Event event;

    switch (Message)
    {
    case WM_PAINT:
        break;

    case WM_DESTROY:
        break;

    case WM_MOUSEMOVE:
        event.Type = Events::IsMouseMove;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateDown;
        event.Mouse.Button = Events::Mouse::ButtonLeft;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateUp;
        event.Mouse.Button = Events::Mouse::ButtonLeft;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateDown;
        event.Mouse.Button = Events::Mouse::ButtonRight;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateUp;
        event.Mouse.Button = Events::Mouse::ButtonRight;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_SIZE:
        break;

    case WM_CLOSE:
        event.Type = Events::IsQuit;
        _Eventer.Push(event);
        break;
    }

    return DefWindowProc(_HWND, Message, WParam, LParam);
}

LRESULT CALLBACK Lt::Graphics::Windows::Window::WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result;

#ifdef _WIN64
    Lt::Graphics::Windows::Window* This = (Lt::Graphics::Windows::Window*)GetWindowLongPtr(Hwnd, GWLP_USERDATA);
#elif _WIN32
    Lt::Graphics::Windows::Window* This = (Lt::Graphics::Windows::Window*)GetWindowLong(Hwnd, GWL_USERDATA);
#endif  

    if (This != nullptr)
        result = This->Handler(Message, WParam, LParam);
    else
        result = DefWindowProc(Hwnd, Message, WParam, LParam);

    return result;
}

Lt::Graphics::Windows::Window::Window(Lt::Core::ErrorHandler* errorHandler, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size, const char* title) :
    _BaseWindow(pos, size, title),
    _ErrorHandler(errorHandler)
{
    Lt::Memory::Zero(&_WNDCLASS, sizeof(WNDCLASS));
    Lt::Memory::Zero(&_MSG, sizeof(MSG));

    _WNDCLASS.hInstance = _HINSTANCE;
    _WNDCLASS.lpszClassName = AppName;
    _WNDCLASS.lpfnWndProc = WndProc;
    _WNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    _WNDCLASS.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _WNDCLASS.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    _WNDCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);

    _ATOM = RegisterClass(&_WNDCLASS);

    if (_ATOM == INVALID_ATOM)
    {
        _ErrorHandler->Message("ATOM == INVALID_ATOM");
    }
    else
    {
        _HWND = CreateWindow(AppName, "", WS_OVERLAPPEDWINDOW, (int)_BaseWindow.Pos().PosX(), (int)_BaseWindow.Pos().PosY(), (int)_BaseWindow.Size().PosX(), (int)_BaseWindow.Size().PosY(), 0, 0, _HINSTANCE, 0);

        if (_HWND == INVALID_HANDLE_VALUE)
        {
            _ErrorHandler->Message("HWND == INVALID_HANDLE_VALUE");
        }
        else
        {
#ifdef _WIN64
            SetWindowLongPtr(_HWND, GWLP_WNDPROC, (LONG_PTR)WndProc);
            SetWindowLongPtr(_HWND, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
            SetWindowLong(_HWND, GWL_WNDPROC, (LONG)WndProc);
            SetWindowLong(_HWND, GWL_USERDATA, (LONG)this);
#endif  

            _HDC = GetDC(_HWND);

            if (_HDC == INVALID_HANDLE_VALUE)
            {
                _ErrorHandler->Message("HDC == INVALID_HANDLE_VALUE");
            }
            else
            {
                Title(title);

                ShowWindow(_HWND, SW_SHOW);
            }
        }
    }
}

Lt::Graphics::Windows::Window::~Window()
{
    if (!_ErrorHandler->Error())
    {
        UnregisterClass(AppName, _HINSTANCE);
        ReleaseDC(_HWND, _HDC);
        PostQuitMessage(0);
    }
}

bool Lt::Graphics::Windows::Window::GetEvent(Lt::Events::Event& event)
{
    if (_Eventer.Running())
    {
        if (PeekMessage(&_MSG, _HWND, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&_MSG);
            DispatchMessage(&_MSG);

            _Eventer.Pop(event);
        }
    }

    return _Eventer.Running();
}

bool Lt::Graphics::Windows::Window::WaitEvent(Lt::Events::Event& event)
{
    BOOL result;

    if (_Eventer.Running())
    {
        if ((result = GetMessage(&_MSG, _HWND, nullptr, nullptr)) != 0)
        {
            if (result == -1)
            {
                _ErrorHandler->Message("GetMessage");
            }
            else
            {
                _Eventer.Pop(event);

                TranslateMessage(&_MSG);
                DispatchMessage(&_MSG);
            }
        }
    }

    return _Eventer.Running();
}

void Lt::Graphics::Windows::Window::StopEvent()
{
    _Eventer.Stop();
}

void Lt::Graphics::Windows::Window::Title(const char* title)
{
    _BaseWindow.Title(title);

    SetWindowText(_HWND, _BaseWindow.Title());
}

const char* Lt::Graphics::Windows::Window::Title()
{
    return _BaseWindow.Title();
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::Window::Size()
{
    return _BaseWindow.Size();
}

const Lt::Graphics::Point2u& Lt::Graphics::Windows::Window::Pos()
{
    return _BaseWindow.Pos();
}