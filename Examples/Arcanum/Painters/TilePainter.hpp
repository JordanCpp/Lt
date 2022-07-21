#ifndef Arcanum_Painters_TilePainter_hpp
#define Arcanum_Painters_TilePainter_hpp

#include <Lt/Graphics/Render.hpp>
#include "../Game/Tile.hpp"

namespace Arcanum
{
	namespace Painters
	{
		class TilePainter
		{
		public:
			TilePainter(Lt::Graphics::Render* render);
			void Draw(Arcanum::Game::Tile* tile, const Lt::Graphics::Point2u& pos);
		private:
			Lt::Graphics::Render* _Render;
		};
	}
}

#endif   