#ifndef Lt_Graphics_BaseWindow_hpp
#define Lt_Graphics_BaseWindow_hpp

#include <Lt/Graphics/Point2i.hpp>
#include <Lt/Containers/StaticString.hpp>

namespace Lt
{
	namespace Graphics
	{
		class BaseWindow
		{
		public:
			BaseWindow(const Lt::Graphics::Point2i& pos, const Lt::Graphics::Point2i& size, const char * title);
			const Lt::Graphics::Point2i& Pos();
			const Lt::Graphics::Point2i& Size();
			const char* Title();
			void Title(const char* source);
		private:
			Lt::Graphics::Point2i _Pos;
			Lt::Graphics::Point2i _Size;
			Lt::Containers::StaticString<128> _Title;
		};
	}
}

#endif    