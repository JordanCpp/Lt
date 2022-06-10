#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Memory.hpp>

void TestMemoryZero()
{
	const Lt::usize bytes = 1024;

	char buffer[bytes];

	Lt::Memory::Zero(buffer, bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer[i] == '\0');
	}
}

void TestMemoryFill()
{
	const Lt::usize bytes = 1024;

	char buffer[bytes];

	Lt::Memory::Fill(buffer, 'j', bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer[i] == 'j');
	}
}

void TestMemoryCopy()
{
	const Lt::usize bytes = 1024;

	char buffer[bytes];
	char buffer2[bytes];

	Lt::Memory::Zero(buffer, bytes);
	Lt::Memory::Fill(buffer2, 'j', bytes);
	Lt::Memory::Copy(buffer, buffer2, bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer[i] == 'j');
	}
}

int main()
{
	TestMemoryZero();
	TestMemoryFill();
	TestMemoryCopy();

	return 0;
}