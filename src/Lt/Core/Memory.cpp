#include <Lt/Core/Memory.hpp>

void* Lt::Memory::Copy(void* dst, const void* src, Lt::usize n)
{
	Lt::usize i, m;
	Lt::usize* wdst = (Lt::usize*)dst;
	Lt::usize* wsrc = (Lt::usize*)src;
	Lt::u8* cdst, * csrc;

	for (i = 0, m = n / sizeof(Lt::usize); i < m; i++)
		*(wdst++) = *(wsrc++);

	cdst = (Lt::u8*)wdst;
	csrc = (Lt::u8*)wsrc;

	for (i = 0, m = n % sizeof(Lt::usize); i < m; i++)
		*(cdst++) = *(csrc++);

	return dst;
}

void* Lt::Memory::Fill(void* dst, Lt::isize value, Lt::usize bytes)
{
	Lt::u8* p = (Lt::u8*)dst;

	while (bytes--)
	{
		*p++ = (Lt::u8)value;
	}

	return dst;
}

void Lt::Memory::Zero(void* dst, Lt::usize bytes)
{
	Fill(dst, 0, bytes);
}