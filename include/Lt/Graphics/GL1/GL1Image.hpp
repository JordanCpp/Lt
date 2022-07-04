#ifndef Lt_Graphics_GL1Image_hpp
#define Lt_Graphics_GL1Image_hpp

#include <Lt/Graphics/Primitives/Point2u.hpp>
#include <Lt/Graphics/Cpu/CpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		class GL1Image
		{
		public:
			GL1Image(Lt::Graphics::CpuImage* cpuImage);
			~GL1Image();
			const Lt::Graphics::Point2u& Size();
			const Lt::usize Id();
		private:
			Lt::usize _Id;
			Lt::Graphics::Point2u _Size;
		};
	}
}

#endif    