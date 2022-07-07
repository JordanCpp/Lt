#ifndef Lt_Core_Types_hpp
#define Lt_Core_Types_hpp

#include <Lt/Core/Config.hpp>

#include <new>

#define nullptr (0)

namespace Lt
{
	typedef signed char i8;
	typedef unsigned char u8;

	typedef signed short i16;
	typedef unsigned short u16;

	typedef signed int i32;
	typedef unsigned int u32;

#if defined(LT_CONFIG_CPU_64)
#if defined(LT_CONFIG_OS_LINUX)
	typedef long unsigned int u64;
	typedef long signed int i64;
#else
	typedef signed long long i64;
	typedef unsigned long long u64;
#endif

#else
	typedef i32 i64;
	typedef u32 u64;
#endif

	typedef i64 isize;
	typedef u64 usize;
}

#endif