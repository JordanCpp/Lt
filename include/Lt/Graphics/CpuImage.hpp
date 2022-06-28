#ifndef Lt_Graphics_CpuImage_hpp
#define Lt_Graphics_CpuImage_hpp

#include <Lt/Graphics/Point2u.hpp>
#include <Lt/Allocators/Allocator.hpp>
#include <Lt/Core/New.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuImage
		{
		public:
			CpuImage();
			void FromNew(const Lt::Graphics::Point2u& size);
			void FromMemory(const Lt::Graphics::Point2u& size, Lt::u8* pixels);
			void FromAllocator(const Lt::Graphics::Point2u& size, Lt::Allocators::Allocator* allocator);
			~CpuImage();
			const Lt::Graphics::Point2u& Size();
			const Lt::u8 Channels();
			Lt::u8* Pixels();
			const Lt::Allocators::Allocator* Allocator();
		private:
			Lt::Graphics::Point2u _Size;
			Lt::u8 _Channels;
			Lt::u8* _Pixels;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif    