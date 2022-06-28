#ifndef Lt_Graphics_CpuImageFromNew_hpp
#define Lt_Graphics_CpuImageFromNew_hpp

#include <Lt/Graphics/BaseCpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuImageFromNew
		{
		public:
			CpuImageFromNew(const Lt::u8 channels, const Lt::Graphics::Point2u& size);
			~CpuImageFromNew();
			const Lt::Graphics::Point2u& Size();
			Lt::u8* Pixels();
			const Lt::u8 Channels();
		private:
			Lt::Graphics::BaseCpuImage _BaseCpuImage;
		};
	}
}

#endif    