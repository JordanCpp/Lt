#ifndef Lt_Widgets_Application_hpp
#define Lt_Widgets_Application_hpp

#include <Lt/Graphics/Render.hpp>

namespace Lt
{
	namespace Widgets
	{
		class Application
		{
		public:
			Application(Lt::Graphics::Window* window, Lt::Graphics::Render* render);
			void Run();
		private:
			Lt::Core::ErrorHandler _ErrorHandler;
			Lt::Graphics::Window* _Window;
			Lt::Graphics::Render* _Render;
		};
	}
}

#endif