#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/Array.hpp>

void TestArray()
{
	const Lt::usize limit = 128;

	Lt::Containers::Array<Lt::usize, limit> array;

	LT_TEST_EQUAL(array.Length() == limit);
	LT_TEST_EQUAL(array.Content() != nullptr);

	for (Lt::usize i = 0; i < array.Length(); i++)
	{
		array[i] = i + 5;
	}

	for (Lt::usize i = 0; i < array.Length(); i++)
	{
		LT_TEST_EQUAL(array[i] == i + 5);
	}
}

int main()
{
	TestArray();

	return 0;
}