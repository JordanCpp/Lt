#ifndef Lt_Graphics_FpsCounter_hpp
#define Lt_Graphics_FpsCounter_hpp

#include <Lt/Core/Ticks.hpp>

namespace Lt
{
	namespace Graphics
	{
		class FpsCounter
		{
		public:
			FpsCounter(Lt::usize milliseconds = 1000);
			Lt::usize Ticks();
			bool Calc();
			void Clear();
			Lt::usize Fps();
		private:
			Lt::usize _Fps;
			Lt::usize _Milliseconds;
			Lt::usize _OldTime;
		};
	}
}

#endif    