#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/Vector.hpp>

int main()
{
	Lt::Containers::Vector<Lt::usize> vector;

	LT_TEST_EQUAL(vector.Capacity() == 0);
	LT_TEST_EQUAL(vector.Length() == 0);
	LT_TEST_EQUAL(vector.Content() == nullptr);
	LT_TEST_EQUAL(vector.Allocator() == nullptr);

	vector.Reserve(128);

	LT_TEST_EQUAL(vector.Capacity() == 128);
	LT_TEST_EQUAL(vector.Length() == 0);
	LT_TEST_EQUAL(vector.Content() != nullptr);
	LT_TEST_EQUAL(vector.Allocator() == nullptr);

	for (Lt::usize i = 0; i < 128; i++)
	{
		vector.Append(i);
		LT_TEST_EQUAL(vector[i] == i);
	}

	vector.Clear();

	LT_TEST_EQUAL(vector.Capacity() == 128);
	LT_TEST_EQUAL(vector.Length() == 0);
	LT_TEST_EQUAL(vector.Content() != nullptr);
	LT_TEST_EQUAL(vector.Allocator() == nullptr);

	return 0;
}