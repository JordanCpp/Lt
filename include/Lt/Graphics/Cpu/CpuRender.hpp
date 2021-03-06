#ifndef Lt_Graphics_CpuRender_hpp
#define Lt_Graphics_CpuRender_hpp

#include <Lt/Graphics/Base/BaseRender.hpp>
#include <Lt/Graphics/Cpu/CpuWindow.hpp>
#include <Lt/Graphics/Cpu/CpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		class CpuRender
		{
		public:
			CpuRender(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::CpuWindow* window);
			const Lt::Graphics::Point2u& Size();
			const Lt::Graphics::Color& Color();
			void Clear();
			void Color(const Lt::Graphics::Color& color);
			void Present();
			Lt::Graphics::CpuImage* Canvas();
			void Pixel(const Lt::Graphics::Point2u& pos);
			const Lt::Graphics::Color& GetPixel(const Lt::Graphics::Point2u& pos);
			void Fill(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
			void Rect(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
			void Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2);
			Lt::u8* Pixels();
			Lt::u8 BytesPerPixel();
		private:
			Lt::Graphics::CpuWindow* _Window;
			Lt::Graphics::BaseRender _BaseRender;
			Lt::Graphics::CpuImage _Canvas;
		};
	}
}

#endif    