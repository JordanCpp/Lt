#include "TilePainter.hpp"
#include <Lt/Core/Assert.hpp>

Arcanum::Painters::TilePainter::TilePainter(Lt::Graphics::Render* render) :
	_Render(render)
{
	LT_ASSERT(_Render != nullptr);
}

void Arcanum::Painters::TilePainter::Draw(Arcanum::Game::Tile* tile, const Lt::Graphics::Point2u& pos)
{
	LT_ASSERT(tile != nullptr);

	_Render->Draw(tile->Body(), pos);
}