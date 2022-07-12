#ifndef Lt_Graphics_Isometric_hpp
#define Lt_Graphics_Isometric_hpp

#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		class Isometric
		{
		public:
			const Lt::Graphics::Point2u& CartesianToIsometric(const Lt::Graphics::Point2u& pt);
			const Lt::Graphics::Point2u& IsometricToCartesian(const Lt::Graphics::Point2u& pt);
		private:
			Lt::Graphics::Point2u _Current;
		};
	}
}

#endif   