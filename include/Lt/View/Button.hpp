#ifndef Lt_View_Button_hpp
#define Lt_View_Button_hpp

#include <Lt/View/Rect.hpp>

namespace Lt
{
	namespace View
	{
		class Button
		{
		public:
			Button(Lt::Graphics::Point2u& pos, Lt::Graphics::Point2u& size);
		private:
			Lt::View::Rect _Rect;
		};
	}
}

#endif