#ifndef Lt_Graphics_GL1Render_hpp
#define Lt_Graphics_GL1Render_hpp

#include <Lt/Graphics/BaseRender.hpp>
#include <Lt/Graphics/GL1Window.hpp>

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
			void Line(const Lt::Graphics::Point2u& pos1, const Lt::Graphics::Point2u& pos2);
			void FillRect(const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
		private:
			Lt::Graphics::Window* _Window;
			Lt::Graphics::BaseRender _BaseRender;
		};
	}
}

#endif    