#ifndef Lt_Graphics_CpuImage_hpp
#define Lt_Graphics_CpuImage_hpp

#include <Lt/Graphics/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuImage
		{
		public:
			enum
			{
				FromNew,
				FromMemory
			};
			CpuImage(const Lt::Graphics::Point2u& size, const Lt::u8 channels);
			CpuImage(const Lt::Graphics::Point2u& size, const Lt::u8 channels, Lt::u8* pixels);
			~CpuImage();
			const Lt::Graphics::Point2u& Size();
			Lt::u8* Pixels();
			const Lt::u8 Channels();
		private:
			Lt::u8 _Source;
			Lt::Graphics::Point2u _Size;
			Lt::u8* _Pixels;
			Lt::u8 _Channels;
		};
	}
}

#endif    