#ifndef Lt_Graphics_BaseRender_hpp
#define Lt_Graphics_BaseRender_hpp

#include <Lt/Graphics/Color.hpp>
#include <Lt/Graphics/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		class BaseRender
		{
		public:
			BaseRender(const Lt::Graphics::Point2u& size);
			const Lt::Graphics::Point2u& Size();
			const Lt::Graphics::Color& Color();
			void Color(const Lt::Graphics::Color& color);
		public:
			/// <summary>
			/// For optimization
			/// </summary>
		    Lt::Graphics::Point2u _Size;
			Lt::Graphics::Color _Current;
		};
	}
}

#endif    