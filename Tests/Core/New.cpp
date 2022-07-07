#include <Lt/Core/TestEqual.hpp>

void TestNewElement()
{
	Lt::usize* result = new Lt::usize;

	LT_TEST_EQUAL(result != nullptr);

	delete result;
}

void TestNewElementArray()
{
	Lt::usize* result = new Lt::usize[128];

	LT_TEST_EQUAL(result != nullptr);

	delete [] result;
}

void TestNewElementPlacement()
{
	Lt::usize ptr;

	Lt::usize* result = new (&ptr) Lt::usize;

	LT_TEST_EQUAL(result != nullptr);
	LT_TEST_EQUAL(result == &ptr);
}

void TestNewElementPlacementArray()
{
	Lt::usize ptr[128];

	Lt::usize* result = new (&ptr) Lt::usize[128];

	LT_TEST_EQUAL(result != nullptr);
	LT_TEST_EQUAL(result == &ptr[0]);
}

int main()
{
	TestNewElement();
	TestNewElementArray();
	TestNewElementPlacement();
	TestNewElementPlacementArray();

	return 0;
}