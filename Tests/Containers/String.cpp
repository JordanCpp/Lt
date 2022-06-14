#include <Lt/Core/TestEqual.hpp>
#include <Lt/Allocators/FixedLinear.hpp>
#include <Lt/Containers/String.hpp>
#include <Lt/Core/Chars.hpp>

void TestContainerStringDefault()
{
	Lt::Containers::String string;

	LT_TEST_EQUAL(string.Content() == nullptr);
	LT_TEST_EQUAL(string.Capacity() == 0);
	LT_TEST_EQUAL(string.Length() == 0);
	LT_TEST_EQUAL(string.Allocator() == nullptr);
}

void TestContainerStringAppendElement()
{
	Lt::Containers::String string;

	string.Append('H');

	LT_TEST_EQUAL(string.Content() != nullptr);
	LT_TEST_EQUAL(string.Capacity() == 3);
	LT_TEST_EQUAL(string.Length() == 1);
	LT_TEST_EQUAL(string.Allocator() == nullptr);
	LT_TEST_EQUAL(string.Content()[0] == 'H');
	LT_TEST_EQUAL(string.Content()[1] == '\0');
}

void TestContainerStringAppendElements()
{
	Lt::Containers::String string;

	string.Append("Hello!");

	LT_TEST_EQUAL(string.Content() != nullptr);
	LT_TEST_EQUAL(string.Length() == 6);
	LT_TEST_EQUAL(string.Allocator() == nullptr);
	LT_TEST_EQUAL(Lt::Chars::Equal(string.Content(), "Hello!") == true);
}

void TestContainerStringAssign()
{
	Lt::Containers::String string;

	string.Assign("Hello!");

	LT_TEST_EQUAL(string.Content() != nullptr);
	LT_TEST_EQUAL(string.Length() == 6);
	LT_TEST_EQUAL(string.Allocator() == nullptr);
	LT_TEST_EQUAL(Lt::Chars::Equal(string.Content(), "Hello!") == true);
}

int main()
{
	TestContainerStringDefault();
	TestContainerStringAppendElement();
	TestContainerStringAppendElements();
	TestContainerStringAssign();

	return 0;
}