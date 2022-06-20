#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/HashMap.hpp>

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

int main()
{
	TestContainersHashNode();

	return 0;
}