#include <Lt/Core/TestEqual.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestAllocatorsFixedLinearInitialize()
{
	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	LT_TEST_EQUAL(allocator.UsedBytes() == 0);
}

void TestAllocatorsFixedLinearAllocate()
{
	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		void* p = allocator.Allocate(1);

		LT_TEST_EQUAL(p != nullptr);

		LT_TEST_EQUAL(allocator.UsedBytes() == i + 1);
	}
}

void TestAllocatorsFixedLinearReallocate()
{
	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	void* ptr = allocator.Allocate(128);

	LT_TEST_EQUAL(ptr != nullptr);
	LT_TEST_EQUAL(allocator.UsedBytes() == 128);

	ptr = allocator.Reallocate(ptr, 256);

	LT_TEST_EQUAL(ptr != nullptr);
	LT_TEST_EQUAL(allocator.UsedBytes() == 128 + 256);
}

int main()
{
	TestAllocatorsFixedLinearInitialize();
	TestAllocatorsFixedLinearAllocate();
	TestAllocatorsFixedLinearReallocate();

	return 0;
}