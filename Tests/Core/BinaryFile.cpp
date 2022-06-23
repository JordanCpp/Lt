#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/BinaryFile.hpp>

void TestCoreBinaryFileInitialize()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Eof() == true);
	LT_TEST_EQUAL(file.Size() == 0);
	LT_TEST_EQUAL(file.Position() == 0);
}

void TestCoreBinaryFileCreate()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Create("TestFiles/Test.txt") == true);
}

void TestCoreBinaryFileDelete()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Delete("TestFiles/Test.txt") == true);
}

void TestCoreBinaryFileRecreate()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Recreate("TestFiles/Test.txt") == true);
}

void TestCoreBinaryFileExist()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Exist("TestFiles/Test.txt") == true);
}

void TestBinaryFileWriting()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Open("TestFiles/Test.txt", Lt::Core::BinaryFile::Mode::Writing) == true);

	LT_TEST_EQUAL(file.Eof() == true);
	LT_TEST_EQUAL(file.Size() == 0);
	LT_TEST_EQUAL(file.Position() == 0);

	const Lt::usize step = 1024;

	for (Lt::usize i = 0; i < step; i++)
	{
		Lt::usize data = +100500;

		LT_TEST_EQUAL(file.Write((Lt::u8*)&data, sizeof(data)) == sizeof(data));

		LT_TEST_EQUAL(file.Eof() == true);
		LT_TEST_EQUAL(file.Size() == (i + 1) * sizeof(data));
		LT_TEST_EQUAL(file.Position() == (i + 1) * sizeof(data));
	}
}

void TestBinaryFileReading()
{
	Lt::Core::BinaryFile file;

	LT_TEST_EQUAL(file.Eof() == true);
	LT_TEST_EQUAL(file.Size() == 0);
	LT_TEST_EQUAL(file.Position() == 0);

	LT_TEST_EQUAL(file.Open("TestFiles/Test.txt", Lt::Core::BinaryFile::Mode::Reading) == true);

	LT_TEST_EQUAL(file.Eof() == false);
	LT_TEST_EQUAL(file.Size() == 1024 * sizeof(Lt::usize));
	LT_TEST_EQUAL(file.Position() == 0);

	Lt::usize ch = 0;
	Lt::usize i = 0;

	while (!file.Eof())
	{
		LT_TEST_EQUAL(file.Read((Lt::u8*)&ch, sizeof(Lt::usize)) == sizeof(Lt::usize));
		LT_TEST_EQUAL(ch == +100500);

		i++;
	}

	LT_TEST_EQUAL(file.Size() == 1024 * sizeof(Lt::usize));
	LT_TEST_EQUAL(file.Position() == 1024 * sizeof(Lt::usize));

	file.Close();

	LT_TEST_EQUAL(file.Size() == 0);
	LT_TEST_EQUAL(file.Position() == 0);

	file.Delete("TestFiles/Test.txt");
}

int main()
{
	TestCoreBinaryFileInitialize();
	TestCoreBinaryFileCreate();
	TestCoreBinaryFileDelete();
	TestCoreBinaryFileRecreate();
	TestCoreBinaryFileExist();
	TestBinaryFileWriting();
	TestBinaryFileReading();

	return 0;
}