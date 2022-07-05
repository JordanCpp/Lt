#ifndef Lt_Widgets_Container_hpp
#define Lt_Widgets_Container_hpp

#include <Lt/Widgets/Widget.hpp>
#include <Lt/Containers/Vector.hpp>

namespace Lt
{
	namespace Widgets
	{
		class Container
		{
		public:
			Container(Lt::Widgets::Widget* parent);
			const Lt::Containers::Vector<Lt::Widgets::Widget*>& Widgets();
		private:
			Lt::Widgets::Widget* _Parent;
			Lt::Containers::Vector<Lt::Widgets::Widget*> _Widgets;
		};
	}
}

#endif