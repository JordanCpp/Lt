#include "Lt/Core/StringToInteger.hpp"
#include "Lt/Core/Chars.hpp"

bool Lt::Core::StringToInteger::Convert(const char* source)
{
    _Result = 0;
    int neg = 0;

    while (Lt::Chars::IsSpace(*source)) source++;

    if (*source == '-')
    {
        neg = 1;
        source++;
    }

    if (*source == '+')
    {
        neg = 0;
        source++;
    }

    while (Lt::Chars::IsDigit(*source))
    {
        _Result = 10 * _Result + (*source - '0');
        source++;
    }

    if (*source != '\0')
    {
        _Result = 0;

        return false;
    }

    if (neg)
        _Result = -_Result;

    return _Result;
}

bool Lt::Core::StringToInteger::Convert(const Lt::Containers::String& source)
{
    return Convert(source.Content());
}

Lt::isize Lt::Core::StringToInteger::Result()
{
	return _Result;
}