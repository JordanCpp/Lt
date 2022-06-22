#ifndef Lt_Widgets_Button_hpp
#define Lt_Widgets_Button_hpp

#include <Lt/Widgets/Widget.hpp>

namespace Lt
{
	namespace Widgets
	{
		class Button : public Lt::Widgets::Widget
		{
		public:
			Button(Lt::Graphics::Window* window, Lt::Graphics::Render* render, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
		private:
		};
	}
}

#endif