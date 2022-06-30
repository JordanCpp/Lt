#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/HashMap.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestContainersHashNode()
{
	Lt::Containers::HashNode<Lt::usize>* node = new Lt::Containers::HashNode<Lt::usize>("Hello");
	node->Content = 42;

	Lt::Containers::HashMap<Lt::usize, 1024> hashMap;

	hashMap.Append(node);

	LT_TEST_EQUAL(hashMap.Find("Hello") != nullptr);

	LT_TEST_EQUAL(hashMap.Find("Hello")->Content == 42);

	LT_TEST_EQUAL(hashMap.Find("World") == nullptr);
}

void TestContainersHashAllocator()
{
	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Containers::HashMap<Lt::usize, 1024> hashMap(&allocator);

	LT_TEST_EQUAL(allocator.UsedBytes() == sizeof(Lt::usize) * 1024);

	Lt::Containers::HashNode<Lt::usize>* node = new Lt::Containers::HashNode<Lt::usize>("Hello");
	node->Content = 42;

	hashMap.Append(node);

	LT_TEST_EQUAL(hashMap.Find("Hello") != nullptr);

	LT_TEST_EQUAL(hashMap.Find("Hello")->Content == 42);

	LT_TEST_EQUAL(hashMap.Find("World") == nullptr);
}

int main()
{
	TestContainersHashNode();
	TestContainersHashAllocator();

	return 0;
}