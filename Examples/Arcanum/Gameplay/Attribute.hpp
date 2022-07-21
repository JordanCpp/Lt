#ifndef Arcanum_Gameplay_Attribute_hpp
#define Arcanum_Gameplay_Attribute_hpp

#include <Lt/Core/Types.hpp>

namespace Arcanum
{
	namespace Gameplay
	{
		class Attribute
		{
		public:
			Attribute();
			Attribute(Lt::usize id, Lt::isize number = 0, Lt::isize percent = 0);
			Lt::usize Id();
			Lt::isize Number();
			Lt::isize Percent();
			void Id(Lt::usize value);
			void Number(Lt::isize value);
			void Percent(Lt::isize value);
		private:
			Lt::usize _Id;
			Lt::isize _Number;
			Lt::isize _Percent;
		};
	}
}

#endif   