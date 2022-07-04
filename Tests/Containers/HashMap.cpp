#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/HashMap.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestContainersHashNode()
{
	Lt::Containers::HashNode<Lt::usize>* node = new Lt::Containers::HashNode<Lt::usize>("Hello");
	node->Content = 42;

	Lt::Containers::HashMap<Lt::usize> hashMap(1024);

	hashMap.Append(node);

	LT_TEST_EQUAL(hashMap.Find("Hello") != nullptr);

	LT_TEST_EQUAL(hashMap.Find("Hello")->Content == 42);

	LT_TEST_EQUAL(hashMap.Find("World") == nullptr);
}

void TestContainersHashAllocator()
{
	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Containers::HashMap<Lt::usize> hashMap(1024, &allocator);

	LT_TEST_EQUAL(allocator.UsedBytes() == sizeof(Lt::usize) * 1024);

	Lt::Containers::HashNode<Lt::usize>* node = new Lt::Containers::HashNode<Lt::usize>("Hello");
	node->Content = 42;

	hashMap.Append(node);

	LT_TEST_EQUAL(hashMap.Find("Hello") != nullptr);
	LT_TEST_EQUAL(hashMap.Find("Hello") == node);
	LT_TEST_EQUAL(hashMap.Find("Hello")->Content == 42);
	LT_TEST_EQUAL(hashMap.Find("World") == nullptr);

	Lt::usize val = 77;

	hashMap.Append("World", val);

	LT_TEST_EQUAL(hashMap.Find("World") != nullptr);
	LT_TEST_EQUAL(hashMap.Find("World")->Content == 77);
}

void TestContainersHashAllocatorAppend()
{
	struct Value
	{
		Lt::usize value;
	};

	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;

	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Containers::HashMap<Value> hashMap(1024, &allocator);

	LT_TEST_EQUAL(allocator.UsedBytes() == sizeof(Value) * 1024);

	Lt::Containers::HashNode<Value>* node = new Lt::Containers::HashNode<Value>("Hello");
	node->Content.value = 42;

	hashMap.Append(node);
	LT_TEST_EQUAL(hashMap.Find("Hello") != nullptr);
	LT_TEST_EQUAL(hashMap.Find("Hello")->Content.value == 42);

	Value value;
	value.value = 77;

	hashMap.Append("World", value);
	LT_TEST_EQUAL(hashMap.Find("World") != nullptr);
	LT_TEST_EQUAL(hashMap.Find("World")->Content.value == 77);
}

int main()
{
	TestContainersHashNode();
	TestContainersHashAllocator();
	TestContainersHashAllocatorAppend();

	return 0;
}