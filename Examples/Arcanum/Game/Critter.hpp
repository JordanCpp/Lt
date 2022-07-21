#ifndef Arcanum_Game_Critter_hpp
#define Arcanum_Game_Critter_hpp

#include "CritterScript.hpp"
#include "../Gameplay/CritterStats.hpp"
#include <Lt/Containers/StaticVector.hpp>
#include "../Gameplay/Perk.hpp"

namespace Arcanum
{
	namespace Game
	{
		class CritterScript;

		class Critter
		{
		public:
			enum
			{
				Perks = 8
			};
		private:
			Arcanum::Game::CritterScript* _Script;
			Arcanum::Gameplay::CritterStats _Stats;
			Lt::Containers::StaticVector<Arcanum::Gameplay::Perk*, Arcanum::Game::Critter::Perks> _Perks;
		};
	}
}

#endif   