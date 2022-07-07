#ifndef Lt_View_Line_hpp
#define Lt_View_Line_hpp

#include <Lt/Graphics/Color.hpp>
#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace View
	{
		class Line
		{
		public:
			Line(const Lt::Graphics::Color& color, const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2);
		private:
			Lt::Graphics::Color _Color;
			Lt::Graphics::Point2u _Pos1;
			Lt::Graphics::Point2u _Pos2;
		};
	}
}

#endif