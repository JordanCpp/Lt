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

void TestCoreDirectoryCreate()
{
	Lt::Core::Directory directory;

	LT_TEST_EQUAL(directory.Create("TestFiles/Test") == true);
	LT_TEST_EQUAL(directory.Create("TestFiles/Test") == false);
}

void TestCoreDirectoryExist()
{
	Lt::Core::Directory directory;

	LT_TEST_EQUAL(directory.Exist("TestFiles/Test") == true);
}

void TestCoreDirectoryDelete()
{
	Lt::Core::Directory directory;

	LT_TEST_EQUAL(directory.Delete("TestFiles/Test") == true);
	LT_TEST_EQUAL(directory.Delete("TestFiles/Test") == false);
}

int main()
{
	TestCoreDirectoryOpen();
	TestCoreDirectoryNext();
	TestCoreDirectoryCreate();
	TestCoreDirectoryExist();
	TestCoreDirectoryDelete();

	return 0;
}