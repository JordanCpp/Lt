#ifndef Lt_Platforms_Windows_Input_Mouse_hpp
#define Lt_Platforms_Windows_Input_Mouse_hpp

#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace Input
	{
		class Mouse
		{
		public:
			const Lt::Graphics::Point2u& Pos();
		private:
			Lt::Graphics::Point2u _Pos;
		};
	}
}

#endif    