#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/BinaryFile.hpp>

void TestBinaryFileReading()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Eof() == true);

	LT_TEST_EQUAL(file.Open("Test.txt", Lt::Core::BinaryFile::Mode::Reading) == true);

	LT_TEST_EQUAL(file.Eof() == false);

	Lt::u8 ch = 0;

	char str[] = "Hello!";

	Lt::usize i = 0;

	while (!file.Eof())
	{
		LT_TEST_EQUAL(file.Read(&ch, 1) == 1);
		LT_TEST_EQUAL(ch == str[i]);

		i++;
	}
}

int main()
{
	TestBinaryFileReading();

	return 0;
}