#ifndef Lt_Platforms_Windows_Graphics_GL1Window_hpp
#define Lt_Platforms_Windows_Graphics_GL1Window_hpp

#include <Lt/Platforms/Windows/Graphics/Window.hpp>

namespace Lt
{
	namespace Graphics
	{
		namespace Windows
		{
			class GL1Window
			{
			public:
				GL1Window(Lt::Core::ErrorHandler* errorHandler, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size, const char* title);
				~GL1Window();
				void Present();
				bool GetEvent(Lt::Events::Event& event);
				void StopEvent();
				void Title(const char* title);
				const char* Title();
				const Lt::Graphics::Point2u& Size();
				const Lt::Graphics::Point2u& Pos();
			private:
				Lt::Graphics::Windows::Window _Window;
				HGLRC _HGLRC;
			};
		}
	}
}

#endif  