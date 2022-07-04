#ifndef Lt_Graphics_Screenshoter_hpp
#define Lt_Graphics_Screenshoter_hpp

#include <Lt/Graphics/Render.hpp>
#include <Lt/Containers/StaticString.hpp>
#include <Lt/Core/DateTime.hpp>
#include <Lt/Core/IntegerToString.hpp>
#include <Lt/Graphics/PixelConverter.hpp>

namespace Lt
{
	namespace Graphics
	{
		class Screenshoter
		{
		public:
			Screenshoter(Lt::Graphics::Render* render, const char* path);
			void Shot();
			const char* Path();
		private:
			void Shot(const char* path);
			Lt::Graphics::Render* _Render;
			Lt::Containers::StaticString<64> _ShortPath;
			Lt::Containers::StaticString<256> _FullPath;
			Lt::DateTime _Current;
			Lt::Core::IntegerToString _Conv;
			Lt::Graphics::PixelConverter _PixelConverter;
		};
	}
}

#endif    