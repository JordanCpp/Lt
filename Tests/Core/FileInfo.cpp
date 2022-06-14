#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/FileInfo.hpp>

void TestFileInfo()
{
	Lt::Core::FileInfo fileInfo;

	fileInfo.Name("Hello!");

	LT_TEST_EQUAL(Lt::Chars::Equal(fileInfo.Name(), "Hello!"));
}

int main()
{
	TestFileInfo();

	return 0;
}