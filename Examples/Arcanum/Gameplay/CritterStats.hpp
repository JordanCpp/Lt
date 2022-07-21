#ifndef Arcanum_Gameplay_CritterStats_hpp
#define Arcanum_Gameplay_CritterStats_hpp

#include <Lt/Containers/Array.hpp>
#include "StatValue.hpp"

namespace Arcanum
{
	namespace Gameplay
	{
		class CritterStats
		{
		public:
			enum
			{
				Strength,
				Constitution,
				Dexterity,
				Beauty,
				Intelligence,
				Willpower,
				Perception,
				Charisma,
				Max
			};
			Lt::usize Value(Lt::usize index);
			Lt::usize Number(Lt::usize index);
			Lt::usize Percent(Lt::usize index);
			void Value(Lt::usize index, Lt::usize value);
			void Number(Lt::usize index, Lt::usize value);
			void Percent(Lt::usize index, Lt::usize value);
		private:
			Lt::Containers::Array<Arcanum::Gameplay::StatValue, Arcanum::Gameplay::CritterStats::Max> _Stats;
		};
	}
}

#endif   