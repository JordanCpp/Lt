#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/StaticVector.hpp>

void TestContainersStaticVectorManual()
{
	const Lt::usize count = 128;

	Lt::Containers::StaticVector<Lt::usize, count> staticVector;

	LT_TEST_EQUAL(staticVector.Capacity() == count);
	LT_TEST_EQUAL(staticVector.Length() == 0);
	LT_TEST_EQUAL(staticVector.Content() != nullptr);
}

void TestContainersStaticVectorAppend()
{
	const Lt::usize count = 128;

	Lt::Containers::StaticVector<Lt::usize, count> staticVector;

	for (Lt::usize i = 0; i < count; i++)
	{
		staticVector.Append(i + 5);

		LT_TEST_EQUAL(staticVector.Capacity() == count);
		LT_TEST_EQUAL(staticVector.Length() == i + 1);
		LT_TEST_EQUAL(staticVector.Content() != nullptr);
		LT_TEST_EQUAL(staticVector[i] == i + 5);
	}
}

void TestContainersStaticVectorClear()
{
	const Lt::usize count = 128;

	Lt::Containers::StaticVector<Lt::usize, count> staticVector;

	for (Lt::usize i = 0; i < count; i++)
	{
		staticVector.Append(i);
	}

	LT_TEST_EQUAL(staticVector.Capacity() == count);
	LT_TEST_EQUAL(staticVector.Length() == count);
	LT_TEST_EQUAL(staticVector.Content() != nullptr);

	staticVector.Clear();

	LT_TEST_EQUAL(staticVector.Capacity() == count);
	LT_TEST_EQUAL(staticVector.Length() == 0);
	LT_TEST_EQUAL(staticVector.Content() != nullptr);
}

int main()
{
	TestContainersStaticVectorManual();
	TestContainersStaticVectorAppend();
	TestContainersStaticVectorClear();

	return 0;
}