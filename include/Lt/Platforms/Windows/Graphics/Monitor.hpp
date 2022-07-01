#ifndef Lt_Platforms_Windows_Graphics_Monitor_hpp
#define Lt_Platforms_Windows_Graphics_Monitor_hpp

#include <Lt/Graphics/Primitives/Point2u.hpp>

namespace Lt
{
	namespace Graphics
	{
		namespace Windows
		{
			class Monitor
			{
			public:
				Monitor();
				const Lt::Graphics::Point2u& Resolution();
			private:
				Lt::Graphics::Point2u _Current;
			};
		}
	}
}

#endif    