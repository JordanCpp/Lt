#ifndef Lt_Graphics_FpsLimiter_hpp
#define Lt_Graphics_FpsLimiter_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Graphics
	{
		class FpsLimiter
		{
		public:
			FpsLimiter(Lt::usize fps = 60);
			void Mark();
			void Throttle() const;
		private:
			Lt::usize _Fps;
			Lt::usize _Ticks;
		};
	}
}

#endif    