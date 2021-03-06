#ifndef Lt_Platforms_Linux_Graphics_CpuWindow_hpp
#define Lt_Platforms_Linux_Graphics_CpuWindow_hpp

#include <Lt/Graphics/Window.hpp>

namespace Lt
{
	namespace Graphics
	{
		namespace Linux
		{
			class CpuWindow
			{
			public:
				CpuWindow(Lt::Core::ErrorHandler& errorHandler, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size, const char* title);
				~CpuWindow();
				void Present(Lt::u8* pixels);
				bool GetEvent(Lt::Events::Event& event);
				void StopEvent();
				void Title(const char* title);
				const char* Title();
				const Lt::Graphics::Point2u& Size();
				const Lt::Graphics::Point2u& Pos();
				bool IsError();
				const char* Message();
			private:
				Lt::Graphics::Linux::Window _Window;
			};
		}
	}
}

#endif    