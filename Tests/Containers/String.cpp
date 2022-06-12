#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/String.hpp>

void TestContainerStringDefault()
{
	Lt::Containers::String string;

	LT_TEST_EQUAL(string.Content() == nullptr);
	LT_TEST_EQUAL(string.Capacity() == 0);
	LT_TEST_EQUAL(string.Length() == 0);
	LT_TEST_EQUAL(string.Allocator() == nullptr);
}

int main()
{
	TestContainerStringDefault();

	return 0;
}