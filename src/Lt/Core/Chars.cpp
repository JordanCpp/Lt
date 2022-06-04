#include <Lt/Core/Chars.hpp>

Lt::usize Lt::Chars::Length(const char* source)
{
	Lt::usize i = 0;

	while (source[i] != '\0')
	{
		i++;
	}

	return i;
}