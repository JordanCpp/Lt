#ifndef Lt_Graphics_CpuImageFromMemory_hpp
#define Lt_Graphics_CpuImageFromMemory_hpp

#include <Lt/Graphics/BaseCpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuImageFromMemory
		{
		public:
			CpuImageFromMemory(const Lt::u8 channels, const Lt::Graphics::Point2u& size, Lt::u8* pixels);
			~CpuImageFromMemory();
			const Lt::Graphics::Point2u& Size();
			Lt::u8* Pixels();
			const Lt::u8 Channels();
		private:
			Lt::Graphics::BaseCpuImage _BaseCpuImage;
		};
	}
}

#endif    