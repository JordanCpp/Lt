#ifndef Lt_Graphics_PixelConverter_hpp
#define Lt_Graphics_PixelConverter_hpp

#include <Lt/Graphics/Color.hpp>
#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		class PixelConverter
		{
		public:
			void Fill(Lt::u8* pixels, const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel, const Lt::Graphics::Color& color);
			void RgbToBgr(Lt::u8* pixels, const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel);
			void BgrToRgb(Lt::u8* pixels, const Lt::Graphics::Point2u& size, const Lt::u8 bytesPerPixel);
		private:
		};
	}
}

#endif    