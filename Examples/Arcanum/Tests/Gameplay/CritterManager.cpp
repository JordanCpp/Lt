#include <Lt/Core/TestEqual.hpp>
#include <Lt/Allocators/FixedLinear.hpp>
#include "../../Managers/CritterManager.hpp"

void TestCritterManagerInit()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::Allocator::Mb * 1);

	Arcanum::Managers::CritterManager manager(&allocator);

	LT_TEST_EQUAL(manager.Allocator() == &allocator);
}

void TestCritterManagerGet()
{
	Lt::Allocators::FixedLinear allocator(Lt::Allocators::Allocator::Mb * 1);

	Arcanum::Managers::CritterManager manager(&allocator);

	Arcanum::Game::Critter* critter = manager.Get();

	LT_TEST_EQUAL(critter != nullptr);
}

int main()
{
	TestCritterManagerInit();
	TestCritterManagerGet();

	return 0;
}