#ifndef Lt_Core_Types_hpp
#define Lt_Core_Types_hpp

#include <Lt/Core/Config.hpp>

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
	typedef signed long long isize;
	typedef unsigned long long usize;
#else
	typedef signed int isize;
	typedef unsigned int usize;
#endif
}

#endif    