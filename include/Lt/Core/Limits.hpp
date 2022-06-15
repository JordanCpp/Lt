#ifndef Lt_Core_Limits_hpp
#define Lt_Core_Limits_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Core
	{
		namespace Limits
		{
			const Lt::i8 i8Max = 127;
			const Lt::i8 i8Min = -(i8Max - 1);

			const Lt::u8 u8Max = 255;
			const Lt::u8 u8Min = 0;

			const Lt::i16 i16Max = 32767;
			const Lt::i16 i16Min = -(i16Max - 1);

			const Lt::u16 u16Max = 65535;
			const Lt::u16 u16Min = 0;

			const Lt::i32 i32Max = 2147483647;
			const Lt::i32 i32Min = -(i32Max - 1);

			const Lt::u32 u32Max = 4294967295;
			const Lt::u32 u32Min = 0;

        #if defined(LT_CONFIG_CPU_64)
			const Lt::isize isizeMax = 9223372036854775807;
			const Lt::isize isizeMin = -(isizeMax - 1);

			const Lt::usize usizeMax = 18446744073709551615;
			const Lt::usize usizeMin = 0;
        #else
			const Lt::isize isizeMax = i32Max;
		    const Lt::isize isizeMin = i32Min;

			const Lt::usize usizeMax = u32Max;
			const Lt::usize usizeMin = u32Min;
        #endif

		}
	}
}

#endif    