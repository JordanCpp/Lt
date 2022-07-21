#ifndef Arcanum_Gameplay_StatValue_hpp
#define Arcanum_Gameplay_StatValue_hpp

#include <Lt/Core/Types.hpp>

namespace Arcanum
{
	namespace Gameplay
	{
		class StatValue
		{
		public:
			StatValue();
			Lt::usize Value();
			Lt::usize Number();
			Lt::usize Percent();
			void Value(Lt::usize value);
			void Number(Lt::usize value);
			void Percent(Lt::usize value);
		private:
			Lt::usize _Value;
			Lt::usize _Number;
			Lt::usize _Percent;
		};
	}
}

#endif   