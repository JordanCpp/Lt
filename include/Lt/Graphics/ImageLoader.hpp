#ifndef Lt_Graphics_ImageLoader_hpp
#define Lt_Graphics_ImageLoader_hpp

#include <Lt/Graphics/Point2u.hpp>
#include <Lt/Core/ErrorHandler.hpp>

namespace Lt
{
	namespace Graphics
	{
		class ImageLoader
		{
		public:
			ImageLoader(Lt::Core::ErrorHandler* errorHandler);
			~ImageLoader();
			void Clear();
			const Lt::Graphics::Point2u& Size();
			Lt::u8 Channels();
			Lt::u8* Pixels();
			void Load(const char* path);
		private:
			Lt::Core::ErrorHandler* _ErrorHandler;
			Lt::Graphics::Point2u _Size;
			Lt::u8 _Channels;
			Lt::u8* _Pixels;
		};
	}
}

#endif    