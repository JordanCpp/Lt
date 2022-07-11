#ifndef Lt_Widgets_Factory_hpp
#define Lt_Widgets_Factory_hpp

#include <Lt/Widgets/Button.hpp>

namespace Lt
{
	namespace Widgets
	{
		class Factory
		{

		public:
			Factory(Lt::Graphics::Window* window, Lt::Graphics::Render* render);
			Factory(Lt::Graphics::Window* window, Lt::Graphics::Render* render, Lt::Allocators::Allocator* allocator);
			~Factory();
			const Lt::Graphics::Window* Window();
			const Lt::Graphics::Render* Render();
			const Lt::Containers::Vector<Lt::Widgets::Widget*> Widgets();
			Lt::Widgets::Button* Button(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
		private:
			Lt::Allocators::Allocator* _Allocator;
			Lt::Graphics::Window* _Window;
			Lt::Graphics::Render* _Render;
			Lt::Containers::Vector<Lt::Widgets::Widget*> _Widgets;
		};
	}
}

#endif