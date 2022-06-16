#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/CircularBuffer.hpp>

void TestContainersCircularBufferInit()
{
	Lt::Containers::CircularBuffer<Lt::usize, 8> circularBuffer;

	LT_TEST_EQUAL(circularBuffer.IsEmpty() == true);
	LT_TEST_EQUAL(circularBuffer.IsFull() == false);
}

void TestContainersCircularBufferFill()
{
	const Lt::usize count = 8;

	Lt::Containers::CircularBuffer<Lt::usize, count> circularBuffer;

	for (Lt::usize i = 0; i < count; i++)
	{
		circularBuffer.Enqueue(i);

		LT_TEST_EQUAL(circularBuffer.IsEmpty() == false);
	}

	LT_TEST_EQUAL(circularBuffer.IsFull() == true);

	for (Lt::usize i = 0; i < count; i++)
	{
		Lt::usize elemet;

		LT_TEST_EQUAL(circularBuffer.IsEmpty() == false);
		LT_TEST_EQUAL(circularBuffer.Dequeue(elemet) == true);
		LT_TEST_EQUAL(circularBuffer.IsFull() == false);
	}

	LT_TEST_EQUAL(circularBuffer.IsEmpty() == true);
}

int main()
{
	TestContainersCircularBufferInit();
	TestContainersCircularBufferFill();

	return 0;
}