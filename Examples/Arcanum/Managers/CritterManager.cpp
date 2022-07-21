#include "CritterManager.hpp"

Arcanum::Managers::CritterManager::CritterManager(Lt::Allocators::Allocator* allocator) :
	_Allocator(allocator)
{
}

Lt::Allocators::Allocator* Arcanum::Managers::CritterManager::Allocator()
{
	return _Allocator;
}

Arcanum::Game::Critter* Arcanum::Managers::CritterManager::Get()
{
	Arcanum::Game::Critter* result = new (_Allocator->Allocate(sizeof(Arcanum::Game::Critter))) Arcanum::Game::Critter;

	return result;
}