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
			const Lt::Graphics::Point2i& Size();
			const Lt::Graphics::Color& Color();
			void Color(const Lt::Graphics::Color& color);
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