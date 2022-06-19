#include <Lt/Core/TestEqual.hpp>
#include <Lt/Containers/StaticString.hpp>

void TestContainersStaticStringCompare()
{
	const Lt::usize limit = 128;

	Lt::Containers::StaticString<limit> string1;
	Lt::Containers::StaticString<limit> string2;

	string1 = "Hello!";
	LT_TEST_EQUAL(string1 == "Hello!");

	string2 = "World!";
	LT_TEST_EQUAL(string2 == "World!");

	string1 = "Hello!";
	string2 = "Hello!";
	LT_TEST_EQUAL(string1 == string2);

	string1 = "Hello!";
	string2 = "World!";
	LT_TEST_EQUAL(string1 != string2);
}

void TestContainersStaticStringManual()
{
	const Lt::usize limit = 128;

	Lt::Containers::StaticString<limit> string;

	LT_TEST_EQUAL(string.Capacity() == limit - 1);
	LT_TEST_EQUAL(string.Length() == 0);
	LT_TEST_EQUAL(string.Content() != nullptr);
}

void TestContainersStaticStringAppendChar()
{
	const Lt::usize limit = 5;

	Lt::Containers::StaticString<limit> string;

	for (Lt::usize i = 0; i < string.Capacity(); i++)
	{
		string.Append((char)i);

		LT_TEST_EQUAL(string.Capacity() == limit - 1);
		LT_TEST_EQUAL(string.Length() == i + 1);
		LT_TEST_EQUAL(string.Content() != nullptr);
		LT_TEST_EQUAL(string[i] == (char)i);
	}
}

void TestContainersStaticStringAppendChars()
{
	const Lt::usize limit = 128;

	Lt::Containers::StaticString<limit> string;

	string.Append("Hello!");

	LT_TEST_EQUAL(Lt::Chars::Equal(string.Content(), "Hello!"));
}

void TestContainersStaticStringClear()
{
	const Lt::usize limit = 128;

	Lt::Containers::StaticString<limit> string;

	string.Append("Hello!");

	string.Clear();

	LT_TEST_EQUAL(string.Capacity() == limit - 1);
	LT_TEST_EQUAL(string.Length() == 0);
	LT_TEST_EQUAL(string.Content() != nullptr);
}

void TestContainersStaticStringAssign()
{
	const Lt::usize limit = 128;

	Lt::Containers::StaticString<limit> string;

	string.Append("Hello!");

	LT_TEST_EQUAL(Lt::Chars::Equal(string.Content(), "Hello!"));
}

int main()
{
	TestContainersStaticStringCompare();
	TestContainersStaticStringManual();
	TestContainersStaticStringAppendChar();
	TestContainersStaticStringAppendChars();
    TestContainersStaticStringClear();
	TestContainersStaticStringAssign();

	return 0;
}