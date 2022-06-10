#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	const Lt::usize size = 15;

	char buffer[size];

	for (Lt::usize i = 0; i < size; i++)
	{
		buffer[i] = '\0';
	}

	Lt::Chars::Concat(buffer, "Hello", size);
	LT_TEST_EQUAL(Lt::Chars::Equal(buffer, "Hello"));

	Lt::Chars::Concat(buffer, " world!", size);
	LT_TEST_EQUAL(Lt::Chars::Equal(buffer, "Hello world!"));

	return 0;
}