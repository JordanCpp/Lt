#ifndef Lt_Graphics_BaseCpuImage_hpp
#define Lt_Graphics_BaseCpuImage_hpp

#include <Lt/Graphics/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		class BaseCpuImage
		{
		public:
			BaseCpuImage(const Lt::u8 channels, const Lt::Graphics::Point2u& size, Lt::u8* pixels);
			const Lt::Graphics::Point2u& Size();
			Lt::u8* Pixels();
			void Pixels(Lt::u8* source);
			const Lt::u8 Channels();
		private:
			Lt::u8 _Channels;
			Lt::Graphics::Point2u _Size;
			Lt::u8* _Pixels;
		};
	}
}

#endif    