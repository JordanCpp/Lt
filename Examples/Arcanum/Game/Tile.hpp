#ifndef Arcanum_Game_Tile_hpp
#define Arcanum_Game_Tile_hpp

#include <Lt/Graphics/Render.hpp>

namespace Arcanum
{
	namespace Game
	{
		class Tile
		{
		public:
			Lt::Graphics::Image* Body();
		private:
			Lt::Graphics::Image* _Body;
		};
	}
}

#endif   