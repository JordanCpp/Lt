#ifndef Lt_Platforms_Windows_Graphics_Window_hpp
#define Lt_Platforms_Windows_Graphics_Window_hpp

#include <Windows.h>
#include <Lt/Graphics/BaseWindow.hpp>
#include <Lt/Core/ErrorHandler.hpp>
#include <Lt/Events/Eventer.hpp>

namespace Lt
{
	namespace Graphics
	{
		namespace Windows
		{
			class Window
			{
			public:
				Window(Lt::Core::ErrorHandler& errorHandler, const Lt::Graphics::Point2i& pos, const Lt::Graphics::Point2i& size, const char* title);
				~Window();
				bool GetEvent(Lt::Events::Event& event);
				void StopEvent();
				void Title(const char* title);
				const char* Title();
				const Lt::Graphics::Point2i& Size();
				const Lt::Graphics::Point2i& Pos();
			private:
				static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
				LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
				Lt::Graphics::BaseWindow _BaseWindow;
				Lt::Events::Eventer _Eventer;
				Lt::Core::ErrorHandler _ErrorHandler;
				WNDCLASS  _WNDCLASS;
				HINSTANCE _HINSTANCE;
				MSG       _MSG;
				ATOM      _ATOM;
			public:
				HWND _HWND;
				HDC  _HDC;
			};
		}
	}
}

#endif    