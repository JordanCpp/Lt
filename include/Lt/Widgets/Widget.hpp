#ifndef Lt_Widgets_Widget_hpp
#define Lt_Widgets_Widget_hpp

#include <Lt/Graphics/Primitives/Rect2u.hpp>
#include <Lt/Graphics/Primitives/Point2u.hpp>
#include <Lt/Graphics/Window.hpp>
#include <Lt/Graphics/Render.hpp>
#include <Lt/Containers/Vector.hpp>

namespace Lt
{
	namespace Widgets
	{
		class Widget
		{
		public:
			typedef void (*ActionCallback)(Lt::Widgets::Widget* source, Lt::usize type, void* content);
			Widget(Lt::Graphics::Window* window, Lt::Graphics::Render* render, const Lt::Graphics::Point2u& pos, const Lt::Graphics::Point2u& size);
			virtual ~Widget();
			const Lt::Graphics::Point2u& Pos();
			const Lt::Graphics::Point2u& Size();
			const Lt::Graphics::Window* Window();
			const Lt::Graphics::Render* Render();
			const Lt::Widgets::Widget* Parent();
			void Parent(Lt::Widgets::Widget* widget);
			void Attach(Lt::Widgets::Widget* widget);
			Lt::Widgets::Widget::ActionCallback Action();
			void Action(Lt::Widgets::Widget::ActionCallback actionCallback);
			void Action(Lt::Widgets::Widget* source, Lt::usize type, void* content);
		private:
			Lt::Widgets::Widget::ActionCallback _Action;
			Lt::Widgets::Widget* _Parent;
			Lt::Graphics::Window* _Window;
			Lt::Graphics::Render* _Render;
			Lt::Graphics::Rect2u _Area;
			Lt::Containers::Vector<Widget*> _Widgets;
		};
	}
}

#endif