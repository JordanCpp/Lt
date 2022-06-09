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

Lt::isize Lt::Chars::Compare(const char* x, const char* y)
{
    while (*x)
    {
        if (*x != *y)
            break;

        x++;
        y++;
    }

    return *(const unsigned char*)x - *(const unsigned char*)y;
}

bool Lt::Chars::Equal(const char* x, const char* y)
{
    return Compare(x, y) == 0;
}

bool Lt::Chars::IsSpace(char symbol)
{
    return symbol == ' ';
}

bool Lt::Chars::IsDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}
