#include "StringToInteger.hpp"
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
    while (Lt::Chars::IsDigit(*source))
    {
        _Result = 10 * _Result + (*source - '0');
        source++;
    }

    if (neg)
        _Result = -_Result;

    return _Result;
}

Lt::isize Lt::Core::StringToInteger::Result()
{
	return _Result;
}