#ifndef Arcanum_Game_CritterScript_hpp
#define Arcanum_Game_CritterScript_hpp

#include "Script.hpp"
#include "Critter.hpp"

namespace Arcanum
{
	namespace Game
	{
		class Critter;

		class CritterScript: public Arcanum::Game::Script
		{
		public:
		private:
			Arcanum::Game::Critter* _Critter;
		};
	}
}

#endif   