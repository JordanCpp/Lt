#ifndef Lt_Graphics_Color_hpp
#define Lt_Graphics_Color_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Graphics
	{
		class Color
		{
		public:
			Color();
			Color(Lt::u8 red, Lt::u8 green, Lt::u8 blue, Lt::u8 alpha = 255);
			Lt::u8 Red() const;
			Lt::u8 Green() const;
			Lt::u8 Blue() const;
			Lt::u8 Alpha() const;
		private:
			Lt::u8 _Red;
			Lt::u8 _Green;
			Lt::u8 _Blue;
			Lt::u8 _Alpha;
		};
	}
}

#endif    