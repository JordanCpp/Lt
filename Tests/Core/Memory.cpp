#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Memory.hpp>

int main()
{
	const Lt::usize bytes = 1024;

	char buffer[bytes];
	char buffer2[bytes];

	Lt::Memory::Zero(buffer, bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer[i] == '\0');
	}

	Lt::Memory::Fill(buffer2, 'j', bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer2[i] == 'j');
	}

	Lt::Memory::Copy(buffer, buffer2, bytes);

	for (Lt::usize i = 0; i < bytes; i++)
	{
		LT_TEST_EQUAL(buffer[i] == 'j');
	}

	return 0;
}