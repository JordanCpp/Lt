#ifndef Lt_Graphics_CpuImageFromAllocator_hpp
#define Lt_Graphics_CpuImageFromAllocator_hpp

#include <Lt/Graphics/BaseCpuImage.hpp>
#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuImageFromAllocator
		{
		public:
			CpuImageFromAllocator(const Lt::u8 channels, const Lt::Graphics::Point2u& size, Lt::Allocators::Allocator* allocator);
			~CpuImageFromAllocator();
			const Lt::Graphics::Point2u& Size();
			Lt::u8* Pixels();
			const Lt::u8 Channels();
			const Lt::Allocators::Allocator* Allocator();
		private:
			Lt::Graphics::BaseCpuImage _BaseCpuImage;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif    