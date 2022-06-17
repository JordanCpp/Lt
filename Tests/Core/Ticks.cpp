#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Ticks.hpp>

void TestCoreTicks()
{
	Lt::usize start = Lt::Core::Ticks();

	LT_TEST_EQUAL(start > 0);

	Lt::Core::Delay(100);

	Lt::usize finish = Lt::Core::Ticks();

	LT_TEST_EQUAL(finish >= start + 99);
}

int main()
{
	TestCoreTicks();

	return 0;
}