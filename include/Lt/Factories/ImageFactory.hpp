#ifndef Lt_Graphics_Factories_ImageFactory_hpp
#define Lt_Graphics_Factories_ImageFactory_hpp

#include <Lt/Allocators/Allocator.hpp>
#include <Lt/Loaders/ImageLoader.hpp>
#include <Lt/Graphics/CpuImage.hpp>

namespace Lt
{
	namespace Factories
	{
		class ImageFactory
		{
		public:
			ImageFactory(Lt::Allocators::Allocator* allocator, Lt::Loaders::ImageLoader* loader);
			Lt::Graphics::CpuImage* Get(const char* path);
		private:
			Lt::Allocators::Allocator* _Allocator;
			Lt::Loaders::ImageLoader* _Loader;
		};
	}
}

#endif    