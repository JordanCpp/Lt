#ifndef Lt_Graphics_BaseRender_hpp
#define Lt_Graphics_BaseRender_hpp

#include <Lt/Graphics/Color.hpp>
#include <Lt/Graphics/Point2i.hpp>

namespace Lt
{
	namespace Graphics
	{
		class BaseRender
		{
		public:
			BaseRender(const Lt::Graphics::Point2i& size);
			const Lt::Graphics::Point2i& Size();
			const Lt::Graphics::Color& Color();
			void Color(const Lt::Graphics::Color& color);
		private:
			Lt::Graphics::Point2i _Size;
			Lt::Graphics::Color _Current;
		};
	}
}

#endif    