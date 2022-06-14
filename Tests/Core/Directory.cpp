#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Directory.hpp>

void TestCoreDirectoryOpen()
{
	Lt::Core::Directory directory;

	LT_TEST_EQUAL(directory.Open("*") == true);
	LT_TEST_EQUAL(directory.Open("blabla") == false);
}

void TestCoreDirectoryNext()
{
	Lt::Core::Directory directory;

	if (directory.Open("*"))
	{
		Lt::Core::FileInfo fileInfo;

		while (directory.Next(fileInfo))
		{
			LT_TEST_EQUAL(Lt::Chars::Length(fileInfo.Name()) > 0);
		}
	}
}

int main()
{
	TestCoreDirectoryOpen();
	TestCoreDirectoryNext();

	return 0;
}