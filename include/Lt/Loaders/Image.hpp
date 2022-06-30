#ifndef Lt_Graphics_Loaders_Image_hpp
#define Lt_Graphics_Loaders_Image_hpp

#include <Lt/Graphics/Point2u.hpp>
#include <Lt/Core/ErrorHandler.hpp>
#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Loaders
	{
		class Image
		{
		public:
			Image(Lt::Core::ErrorHandler* errorHandler, Lt::Allocators::Allocator* allocator);
			~Image();
			void Clear();
			const Lt::Graphics::Point2u& Size();
			const Lt::u8 Channels();
			const Lt::u8* Pixels();
			void Load(const char* path);
		private:
			Lt::Core::ErrorHandler* _ErrorHandler;
			Lt::Allocators::Allocator* _Allocator;
			Lt::Graphics::Point2u _Size;
			Lt::u8 _Channels;
			Lt::u8* _Pixels;
		};
	}
}

#endif    