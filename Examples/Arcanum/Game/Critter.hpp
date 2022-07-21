#ifndef Arcanum_Game_Critter_hpp
#define Arcanum_Game_Critter_hpp

#include "CritterScript.hpp"
#include "../Gameplay/CritterStats.hpp"

namespace Arcanum
{
	namespace Game
	{
		class CritterScript;

		class Critter
		{
		public:
		private:
			Arcanum::Game::CritterScript* _Script;
			Arcanum::Gameplay::CritterStats _Stats;
		};
	}
}

#endif   