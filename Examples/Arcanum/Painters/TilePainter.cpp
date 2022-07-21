#include "TilePainter.hpp"

Arcanum::Painters::TilePainter::TilePainter(Lt::Graphics::Render* render) :
	_Render(render)
{
}

void Arcanum::Painters::TilePainter::Draw(Arcanum::Game::Tile* tile, const Lt::Graphics::Point2u& pos)
{
	_Render->Draw(tile->Body(), pos);
}