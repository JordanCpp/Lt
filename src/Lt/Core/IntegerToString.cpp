#include <Lt/Core/IntegerToString.hpp>

Lt::Core::IntegerToString::IntegerToString()
{
}

bool Lt::Core::IntegerToString::Convert(Lt::isize num, Lt::u8 base)
{

    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        _Buffer[i++] = '0';
        _Buffer[i] = '\0';
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        _Buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        _Buffer[i++] = '-';

    _Buffer[i] = '\0'; // Append string terminator

    // Reverse the string
    Reverse(_Buffer, i);

    return true;
}

const char* Lt::Core::IntegerToString::Result()
{
    return _Buffer;
}

void Lt::Core::IntegerToString::Swap(char& t1, char& t2)
{
    char tmp = t1;
    t1 = t2;
    t2 = tmp;
}

void Lt::Core::IntegerToString::Reverse(char* str, Lt::usize length)
{
    Lt::usize start = 0;
    Lt::usize end = length - 1;

    while (start < end)
    {
        Swap(*(str + start), *(str + end));
        start++;
        end--;
    }
}