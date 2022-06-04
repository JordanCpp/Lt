#ifndef Lt_Core_Types_hpp
#define Lt_Core_Types_hpp

#ifdef __cplusplus
#define nullptr 0
#else
#define nullptr ((void *)0)
#endif

namespace Lt
{
	typedef signed char i8;
	typedef unsigned char u8;

	typedef signed short i16;
	typedef unsigned short u16;

	typedef signed int i32;
	typedef unsigned int u32;

	typedef signed int isize;
	typedef unsigned long long usize;
}

#endif    