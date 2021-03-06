#ifndef Lt_Graphics_BaseWindow_hpp
#define Lt_Graphics_BaseWindow_hpp

#include <Lt/Graphics/Primitives/Point2u.hpp>
#include <Lt/Containers/StaticString.hpp>

namespace Lt
{
	namespace Graphics
	{
		class BaseWindow
		{
		public:
			BaseWindow(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size, const char * title);
			const Lt::Graphics::Point2u& Pos();
			const Lt::Graphics::Point2u& Size();
			const char* Title();
			void Title(const char* source);
		private:
			Lt::Graphics::Point2u _Pos;
			Lt::Graphics::Point2u _Size;
			Lt::Containers::StaticString<128> _Title;
		};
	}
}

#endif    