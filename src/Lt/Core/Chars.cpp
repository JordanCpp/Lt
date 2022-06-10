#include <Lt/Core/Chars.hpp>
#include <Lt/Core/Memory.hpp>

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

Lt::usize Lt::Chars::Copy(char* dst, const char* src, Lt::usize maxlen)
{
    const size_t srclen = Length(src);

    if (srclen + 1 < maxlen)
    {
        Memory::Copy(dst, src, srclen + 1);
    }
    else if (maxlen != 0)
    {
        Memory::Copy(dst, src, maxlen - 1);
        dst[maxlen - 1] = '\0';
    }

    return srclen;
}

Lt::usize Lt::Chars::Concat(char* dst, const char* src, Lt::usize dsize)
{
	const char* odst = dst;
	const char* osrc = src;
	size_t n = dsize;
	size_t dlen;


	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;

	if (n-- == 0)
		return(dlen + Length(src));
	while (*src != '\0') {
		if (n != 0) {
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';

	return(dlen + (src - osrc));
}