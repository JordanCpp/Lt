#ifndef Lt_Graphics_PixelCalculator_hpp
#define Lt_Graphics_PixelCalculator_hpp

#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		class PixelCalculator
		{
		public:
			Lt::usize Calc(const Lt::Graphics::Point2u& size, Lt::u8 BytesPerPixel);
		private:
		};
	}
}

#endif    