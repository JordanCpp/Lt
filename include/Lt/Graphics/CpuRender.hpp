#ifndef Lt_Graphics_CpuRender_hpp
#define Lt_Graphics_CpuRender_hpp

#include <Lt/Graphics/BaseRender.hpp>
#include <Lt/Graphics/CpuWindow.hpp>
#include <Lt/Graphics/CpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuRender
		{
		public:
			CpuRender(Lt::Graphics::CpuWindow* window);
			void Present();
			Lt::Graphics::CpuImage* Canvas();
		private:
			Lt::Graphics::CpuWindow* _Window;
			Lt::Graphics::BaseRender _BaseRender;
			Lt::Graphics::CpuImage _Canvas;
		};
	}
}

#endif    