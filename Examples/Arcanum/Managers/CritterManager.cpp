#include "CritterManager.hpp"

Arcanum::Managers::CritterManager::CritterManager(Lt::Allocators::Allocator* allocator) :
	_Allocator(allocator)
{
}

Arcanum::Game::Critter* Arcanum::Managers::CritterManager::Get()
{
	Arcanum::Game::Critter* result = new (_Allocator->Allocate(sizeof(Arcanum::Game::Critter))) Arcanum::Game::Critter;

	return result;
}