#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/TextFile.hpp>

void TestTextFileReading()
{
	Lt::Core::TextFile file;

	LT_TEST_EQUAL(file.Eof() == true);

	LT_TEST_EQUAL(file.Open("TestFiles/TextFile.txt") == true);

	LT_TEST_EQUAL(file.Eof() == false);

	char str[] = "Hello!";

	Lt::usize i = 0;

	while (!file.Eof())
	{
		LT_TEST_EQUAL(file.Read() == str[i]);

		i++;
	}
}

int main()
{
	TestTextFileReading();

	return 0;
}