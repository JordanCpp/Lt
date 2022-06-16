#ifndef Lt_Graphics_BaseRender_hpp
#define Lt_Graphics_BaseRender_hpp

#include <Lt/Graphics/Color.hpp>

namespace Lt
{
	namespace Graphics
	{
		class BaseRender
		{
		public:
			const Lt::Graphics::Color& Color();
			void Color(const Lt::Graphics::Color& color);
		private:
			Lt::Graphics::Color _Current;
		};
	}
}

#endif    