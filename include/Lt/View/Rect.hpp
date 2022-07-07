#ifndef Lt_View_Rect_hpp
#define Lt_View_Rect_hpp

#include <Lt/Graphics/Color.hpp>
#include <Lt/Graphics/Primitives/Rect2u.hpp>
#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace View
	{
		class Rect
		{
		public:
			Rect(Lt::Graphics::Color& color, Lt::Graphics::Point2u& pos, Lt::Graphics::Point2u& size);
		private:
			Lt::Graphics::Color _Color;
			Lt::Graphics::Rect2u _Rect;
		};
	}
}

#endif