#include <Lt/Core/TestEqual.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

int main()
{
	const size_t bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	Lt_TestEqual(allocator.UsedBytes() == 0);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		void* p = allocator.Allocate(1);

		Lt_TestEqual(p != nullptr);

		Lt_TestEqual(allocator.UsedBytes() == i + 1);
	}

	return 0;
}