#ifndef Lt_Platforms_Linux_Graphics_Window_hpp
#define Lt_Platforms_Linux_Graphics_Window_hpp

#include <Lt/Graphics/BaseWindow.hpp>
#include <Lt/Core/ErrorHandler.hpp>
#include <Lt/Events/Eventer.hpp>

namespace Lt
{
	namespace Graphics
	{
		namespace Linux
		{
			class Window
			{
			public:
				Window(Lt::Core::ErrorHandler& errorHandler, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size, const char* title);
				~Window();
				bool GetEvent(Lt::Events::Event& event);
				void StopEvent();
				void Title(const char* title);
				const char* Title();
				const Lt::Graphics::Point2u& Size();
				const Lt::Graphics::Point2u& Pos();
			private:
				Lt::Graphics::BaseWindow _BaseWindow;
				Lt::Events::Eventer _Eventer;
				Lt::Core::ErrorHandler _ErrorHandler;
			};
		}
	}
}

#endif    