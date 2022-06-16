#ifndef Lt_Platforms_Windows_Graphics_CpuWindow_hpp
#define Lt_Platforms_Windows_Graphics_CpuWindow_hpp

#include <Lt/Graphics/Window.hpp>
#include <Lt/Graphics/Color.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuWindow
		{
		public:
			CpuWindow(Lt::Core::ErrorHandler& errorHandler, const Lt::Graphics::Point2i& pos, const Lt::Graphics::Point2i& size, const char * title);
			~CpuWindow();
			void Present(Lt::Graphics::Color* pixels);
			bool GetEvent(Lt::Events::Event& event);
			void StopEvent();
			void Title(const char * title);
			const char* Title();
			const Lt::Graphics::Point2i& Size();
			const Lt::Graphics::Point2i& Pos();
			bool IsError();
			const char* Message();
		private:
			Lt::Graphics::Window _Window;
			BITMAPINFO _BITMAPINFO;
		};
	}
}

#endif    