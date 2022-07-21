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
			Lt::usize Number();
			Lt::usize Percent();
			void Number(Lt::usize value);
			void Percent(Lt::usize value);
		private:
			Lt::usize _Number;
			Lt::usize _Percent;
		};
	}
}

#endif   