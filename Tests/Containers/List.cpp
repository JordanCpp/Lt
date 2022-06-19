#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/List.hpp>

void TestContainersListNodeInit()
{
	Lt::Containers::ListNode<Lt::usize> listNode;

	LT_TEST_EQUAL(listNode.Next == nullptr);
	LT_TEST_EQUAL(listNode.Prev == nullptr);
}

void TestContainersListInit()
{
	Lt::Containers::List<Lt::usize> list;

	LT_TEST_EQUAL(list.Head == nullptr);
	LT_TEST_EQUAL(list.Tail == nullptr);
}

void TestContainersListAppend()
{
	const Lt::usize limit = 128;

	Lt::Containers::List<Lt::usize> list;

	for (Lt::usize i = 0; i < limit; i++)
	{
		Lt::Containers::ListNode<Lt::usize>* element = new Lt::Containers::ListNode<Lt::usize>;

		element->Content = i;

		list.Append(element);
	}

	Lt::usize j = 0;

	for (Lt::Containers::ListNode<Lt::usize> * i = list.Head; i != nullptr; i = i->Next)
	{
		LT_TEST_EQUAL(i->Content == j);

		j++;
	}
}

int main()
{
	TestContainersListNodeInit();
	TestContainersListInit();
	TestContainersListAppend();

	return 0;
}