#ifndef Lt_Graphics_GL1Render_hpp
#define Lt_Graphics_GL1Render_hpp

#include <Lt/Graphics/Base/BaseRender.hpp>
#include <Lt/Graphics/GL1/GL1Window.hpp>
#include <Lt/Graphics/Image.hpp>

namespace Lt
{
	namespace Graphics
	{
		class GL1Render
		{
		public:
			GL1Render(Lt::Core::ErrorHandler& errorHandler, Lt::Graphics::Window* window);
			const Lt::Graphics::Point2u& Size();
			const Lt::Graphics::Color& Color();
			void Clear();
			void Color(const Lt::Graphics::Color& color);
			void Present();
			Lt::Graphics::Image* Canvas();
			void Pixel(const Lt::Graphics::Point2u& pos);
			const Lt::Graphics::Color& GetPixel(const Lt::Graphics::Point2u& pos);
			void FillRect(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
			void Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2);
			Lt::u8* Pixels();
			Lt::u8 Channels();
		private:
			Lt::Graphics::Window* _Window;
			Lt::Graphics::BaseRender _BaseRender;
			Lt::Graphics::Image _Canvas;
		};
	}
}

#endif    