#ifndef Arcanum_Game_LocationScript_hpp
#define Arcanum_Game_LocationScript_hpp

#include "Location.hpp"
#include "Critter.hpp"

namespace Arcanum
{
	namespace Game
	{
		class Location;

		class LocationScript : public Arcanum::Game::Script
		{
		public:
		private:
			Arcanum::Game::Location* _Location;
		};
	}
}

#endif   