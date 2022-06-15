#ifndef Lt_Graphics_CpuImage_hpp
#define Lt_Graphics_CpuImage_hpp

#include <Lt/Graphics/Point2i.hpp>
#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuImage
		{
		public:
			CpuImage(const Lt::Graphics::Point2i& size, Lt::Allocators::Allocator* allocator);
			~CpuImage();
			const Lt::Graphics::Point2i& Size();
			const Lt::u8 Channels();
			Lt::u8* Pixels();
			Lt::Allocators::Allocator* Allocator();
		private:
			Lt::Graphics::Point2i _Size;
			Lt::u8 _Channels;
			Lt::u8* _Pixels;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif    